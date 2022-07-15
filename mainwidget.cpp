/*
   Copyright 2022 MaratIK

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QKeyEvent>
#include <QApplication>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->actionExit->setShortcutContext(Qt::ShortcutContext::WidgetWithChildrenShortcut);
    connect(ui->actionExit, &QAction::triggered, &QApplication::quit);
}

MainWidget::~MainWidget()
{
    delete ui;
}

QGraphicsView *MainWidget::graphicsView() const
{
    return ui->graphicsView;
}

void MainWidget::keyPressEvent(QKeyEvent *event)
{
    if (false && event->key() == Qt::Key::Key_Escape) {
        QApplication::quit();
    } else {
        QWidget::keyPressEvent(event);
    }
}
