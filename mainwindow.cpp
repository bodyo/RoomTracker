#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpUi()
{
    ui->tabWidget->setTabText(0, "Main");
    ui->tabWidget->setTabText(1, "Shopping list");
    ui->tabWidget->setTabText(2, "Schedule");

    connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::showMainTextInputDialog);
    connect(ui->pushButton_2, &QPushButton::pressed, this, &MainWindow::showShopListTextInputDialog);
    connect(ui->pushButton_3, &QPushButton::pressed, this, &MainWindow::showToDoTextInputDialog);
}

void MainWindow::addItemToBuy(QString &itemName, QListWidget *listWidget)
{
    QListWidgetItem* item = new QListWidgetItem(itemName, listWidget);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
//    auto pushButton = new QPushButton("Delete");
}

void MainWindow::showMainTextInputDialog()
{
    auto text = showInputDialog({"Add new item"}, {"Good for buying:"});
    if (!text.isEmpty())
        addItemToBuy(text, ui->listWidget);
}

void MainWindow::showShopListTextInputDialog()
{
    auto text = showInputDialog({"Add new item"}, {"Good for buying:"});
    if (!text.isEmpty())
        addItemToBuy(text, ui->listWidget_3);
}

void MainWindow::showToDoTextInputDialog()
{
    auto text = showInputDialog({"Add new ToDo item"}, {"To Do:"});
    if (!text.isEmpty())
        addItemToBuy(text, ui->listWidget_2);
}

QString MainWindow::showInputDialog(const QString &title, const QString &label)
{
    bool ok;
    QString text = QInputDialog::getText(this, title,
                                         label, QLineEdit::Normal,
                                         QString(), &ok);
    return ok ? text : QString();
}
