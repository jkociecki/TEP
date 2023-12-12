#include "../inclulde/CNodeOneArguemnt.h"
#include <cmath>

double CNodeOneArgument::evaluate() const
{
    double child_value = child->evaluate();
    if(operatation == "sin") return sin(child_value);
    if(operatation == "cos") return cos(child_value);
    return 0;
}

std::string CNodeOneArgument::toString() const
{
    return operatation;
}

std::vector<CNode*> CNodeOneArgument::getVariables() const
{
    return std::vector<CNode*>() = {child};
}

CNodeOneArgument::~CNodeOneArgument()
{
    delete child;
}

CNodeOneArgument* CNodeOneArgument::clone() const
{
    return new CNodeOneArgument(*this);
}