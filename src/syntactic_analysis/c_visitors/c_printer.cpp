#include "syntactic_analysis/c_visitors//c_printer.hpp"
#include "syntactic_analysis/c_node.hpp"

void CPrinter::visit(Program* node){
    std::cout << "Program: " << std::endl;
    if (node->func_ptr){
        node->func_ptr->accept(this);
    }
}

void CPrinter::visit(Function* node){
    std::cout << "Function: Name: " << node->name << std::endl;
    if (node->state_ptr){
        node->state_ptr->accept(this);
    }
}

void CPrinter::visit(Statement* node){
    std::cout << "Statement: Return " << std::endl;
    if (node->exp_ptr){
        node->exp_ptr->accept(this);
    }
}

void CPrinter::visit(UnaryOp* node){
    Token t(node->type);
    std::cout << "Expression: Unary: " << t.get_type_name(t.get_type()) << std::endl;
    if (node->exp_ptr){
        node->exp_ptr->accept(this);
    }
}

void CPrinter::visit(BinaryOp* node){
    std::cout << "Expression: Binary" << std::endl;
    if (node->exp_left){
        std::cout << "LHS: ";
        node->exp_left->accept(this);
    }
    Token t(node->op);
    std::cout << "Operator: " << t.get_type_name(node->op) << std::endl;
    if (node->exp_right){
        std::cout << "RHS: ";
        node->exp_right->accept(this);
    }
}

void CPrinter::visit(Constant* node){
    std::cout << "Expression: Constant(" << node->value << ")" << std::endl;
}