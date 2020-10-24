#include "b64img.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator trans;
    if (trans.load(QLocale(), "b64img", "_", a.applicationDirPath() + "/translations", ".qm"))
        a.installTranslator(&trans);
    b64img w;
    w.show();
    return a.exec();
}
