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
            QMessageBox::critical(this, tr("Read Error"), tr("Cannot read file!"), QMessageBox::Ok, QMessageBox::Ok);
            return;
        }
        QByteArray img = f.readAll();
        ui->plainTextEdit->setPlainText(QString::fromUtf8(img.toBase64(QByteArray::Base64Encoding)));
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
