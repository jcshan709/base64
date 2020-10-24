#include "b64img.h"
#include "ui_b64img.h"

b64img::b64img(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::b64img)
{
    ui->setupUi(this);
}

b64img::~b64img()
{
    delete ui;
}


void b64img::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(BrowseImageFile());
}

QString b64img::BrowseImageFile() {
    return QFileDialog::getOpenFileName(this, tr("Choose an image file"), ".", tr("Supported image file(*.jpg; *.png; *.jpeg; *.gif; *.ico);;All files(*.*)"));
}

void b64img::on_pushButton_clicked()
{
    QFile f(ui->lineEdit->text());
    if (!f.exists())
        QMessageBox::warning(this, tr("Not Found"), tr("File doesn\'t exists!"), QMessageBox::Ok, QMessageBox::Ok);
    else {
        if (!f.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Open Error"), tr("Cannot open file!"), QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        QByteArray img = f.readAll();
        ui->plainTextEdit->setPlainText(QString::fromUtf8(img.toBase64()));
    }
}

void b64img::copy(QString s) {
    QClipboard *clip = QApplication::clipboard();
    clip->setText(s);
}

QString b64img::paste() {
    QClipboard *clip = QApplication::clipboard();
    return clip->text();
}

void b64img::on_pushButton_3_clicked()
{
    copy(ui->plainTextEdit->toPlainText());
    QMessageBox::information(this, tr("Copy"), tr("Text copied successfully"), QMessageBox::Ok, QMessageBox::Ok);
}

void b64img::on_pushButton_4_clicked()
{
    ui->plainTextEdit->setPlainText("");
}

void b64img::on_pushButton_5_clicked()
{
    QUrl help("https://github.com/sjc0910/b64img/wiki");
    QDesktopServices::openUrl(help);
}

void b64img::closeEvent(QCloseEvent *event) {
    auto ans = QMessageBox::warning(this, tr("Exit program"), tr("Are you sure to exit this program?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (ans == QMessageBox::Yes) {
        event->accept();
        qApp->exit();
    }
    event->ignore();
}

void b64img::on_pushButton_7_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Choose an image file to save"), ".", tr("Supported image file(*.jpg; *.png; *.jpeg; *.gif; *.ico);;All files(*.*)"));
    if (path == "") return;
    QFile f(path);
    if (!f.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, tr("Open Error"), tr("Cannot open file!"));
        return;
    }
    QByteArray b64 = ui->plainTextEdit->toPlainText().toUtf8();
    b64 = QByteArray::fromBase64(b64);
    f.write(b64);
    f.close();
}

void b64img::on_pushButton_6_clicked()
{
    ui->plainTextEdit->setPlainText(paste());
}
