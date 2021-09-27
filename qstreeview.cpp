#include "qstreeview.h"
#include "qstylefactory.h"

QSTreeView::QSTreeView(QWidget *parent) : QTreeView(parent)
{
    this->setStyle(QStyleFactory::create("windows"));
}

QSTreeView::~QSTreeView(){
    if(this->tree_model != NULL){
        delete this->tree_model;
    }
}

void QSTreeView::setTreeData(QSolverJob* qSolverJob){
    this->qSolverJob = qSolverJob;
    this->tree_model = new TreeModel(qSolverJob);
    this->setModel(this->tree_model);
}