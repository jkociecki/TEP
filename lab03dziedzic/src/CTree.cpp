#include "../inclulde/CTree.h"
#include <sstream>


CTree::CTree(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;
    std::vector<std::string> tokens;
    while (iss >> token)
    {
        tokens.push_back(token);
    }
    root = createTreeRecursive(tokens);
}

double CTree::evaluate() const
{
    return root->evaluate();
}



CNode* CTree::createTreeRecursive(std::vector<std::string>& expression)
{
    if (expression.empty())
    {
        return nullptr;
    }


    std::string token = expression.front();
    expression.erase(expression.begin());
    if (isOperatorTwoArgument(token))
    {
        CNode* left = createTreeRecursive(expression);
        CNode* right = createTreeRecursive(expression);
        return new CNodeTwoArguments(token, left, right);
    }
    else if (isOperatorOneArgument(token))
    {
        CNode* child = createTreeRecursive(expression);
        return new CNodeOneArgument(token, child);
    }
    else if (isNumber(token))
    {
        std::stringstream ss(token);
        double value;
        ss >> value;
        return new CLeaf(value);
    }
    else
    {
        return new CVariable(token, 0);
    }
}



bool CTree::isOperatorTwoArgument(const std::string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool CTree::isNumber(const std::string &token)
{
    for (char c : token)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}


bool CTree::isOperatorOneArgument(const std::string &token)
{
    return token == "sin" || token == "cos";
}



