#ifndef TOKEN_HPP    
#define TOKEN_HPP

#include <string>
#include <cassert>

//Lexer TokenTypes
enum TokenType {
    Identifier,
    ConstantLiteral,
    Int_key,
    Void_key,
    Return_key,
    Open_parenthesis,
    Close_parenthesis,
    Open_brace,
    Close_brace,
    Semicolon,
    Complement,
    Negation,
    Decrement,
    Addition,
    Multiplication,
    Division,
    Modulus
};

class Token {
    public:

    //Initalizes tokens
    Token(TokenType t);

    //Initalizes Constants
    Token(TokenType t, int value);

    //Initalizes Identifiers
    Token(TokenType t, std::string name);

    //RETURNS: the token's type
    TokenType get_type();

    //RETURNS: the token's type name
    std::string get_type_name(TokenType type);

    //RETURNS: a Constant's value
    int get_value();

    //RETURNS: an Identifier's name
    std::string get_name();
    
    //RETURNS: if expected == this
    bool expect(TokenType expected);

    private:

    TokenType type;
    int value;
    std::string name;
};

#endif