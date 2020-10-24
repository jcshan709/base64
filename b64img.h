#ifndef B64IMG_H
#define B64IMG_H

#include "global.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class b64img; }
QT_END_NAMESPACE

class b64img : public QMainWindow
{
    Q_OBJECT

public:
    b64img(QWidget *parent = nullptr);
    ~b64img();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::b64img *ui;

private:
    QString BrowseImageFile();
    void copy(QString s);
    QString paste();

protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // B64IMG_H
