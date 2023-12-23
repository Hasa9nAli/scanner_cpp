//
// Created by hasan on 17/12/23.
//

#ifndef UNTITLED6_SCANNERCOMPONENT_H
#define UNTITLED6_SCANNERCOMPONENT_H
#include <iostream>
#include <cstring>
#include <limits>

using namespace std ;
namespace HasanScanner{
    bool isSpecialCharacter(char line){
        char special[26] = {
                '=', '+','-',')','(', '*', '&','^','%','$','#','@'
                , '!', '~', '?', '.', '<','>', '`','/', ':', ';', '{','}','[',']'
        };
        for (int i = 0; i < strlen(special); i++) {
            if (line == special[i])
                return true;
        }
        return false;
    }

    bool isDoubleSpecialCharacter(const string& token) {
        string doubleSpecialCharacter[] = {
                "++", "--", "!=", "+=", "*=", "/=","&&","||", "==","<<", ">>"
        };
        for(int i =0 ; i < 9 ; i++)
            if (token == doubleSpecialCharacter[i]) {
                return true;
            }
        return false;
    }

    bool isKeyword(const string& token){
        string keywords[] = {
                "int", "float", "char","long", "long int" , "long long int", "double",
                "unsigned", "unsigned int" , "signed int", "auto" , "break", "continue",
                "typeof", "typedef" , "union" , "FILE", "NULL", "main", "void",
                "cout", "namespace", "include","std", "cstring", "string",
                "const",
        };
        for(const string& keyword: keywords){
            if(keyword == token) return true ;
        }
        return false;

    }

    bool isOperation(string& token){
        string operations[6] = {
                "+", "-","=","*","/","%"
        };
        for(const string& oneOperation : operations)
            if(token == oneOperation) return true ;
        return false ;
    }

    bool isNumberValue(string token){
        try {
            if(stoi(token) >= numeric_limits<int>::min()&& stoi(token)<= numeric_limits<int>::max() )
                return true;
            else return false;
        }catch (exception e ){
            return false ;
        }
    }

    bool isSpecialOfTesting(const string& token ){
        string special[26] = {
                "=", "+","-",")","(", "*", "&","^","%","$","#","@"
                , "!", "~", "?", ".", "<",">", "`","/", ":", ";","{","}",
                "[", "]"
        };
        for(const string& element : special)
            if (element == token)
                return true;
        return false ;
    }
    bool isCharacterSpace(char character){
        if(character == ' ')
            return true ;
        return false;
    }

    string classificationOfToken(string tokens[], int indexOfLastPointOfToken){

        for(int indexOfToken = 0 ; indexOfToken < indexOfLastPointOfToken;indexOfToken++){
            if (!tokens[indexOfToken].empty() &&tokens[indexOfToken]!= " " ) {
                if (isOperation(tokens[indexOfToken]))
                    cout << tokens[indexOfToken] << " -> is Operation\n";
                else if (isDoubleSpecialCharacter(tokens[indexOfToken]))
                    cout << tokens[indexOfToken] << " -> is Double Special\n";

                else if (isKeyword(tokens[indexOfToken]))
                    cout << tokens[indexOfToken] << " -> is Keyword\n";

                else if(isSpecialOfTesting(tokens[indexOfToken]))
                    cout << tokens[indexOfToken] << " -> is special character\n";
                else if (isNumberValue(tokens[indexOfToken]))
                    cout << tokens[indexOfToken] << " -> is Number\n";
                else
                    cout << tokens[indexOfToken] << " -> is Identifier\n";


            }
        }
        return  "";
    }

}
#endif //UNTITLED6_SCANNERCOMPONENT_H
