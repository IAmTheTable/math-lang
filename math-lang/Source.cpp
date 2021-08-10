/* 
* Writer: Table(Aiden)
* Todo: parse, lex, tokenize, compile to x86
*/

#include "tokenizer/tokenizer.hpp"
#include "parser/parser.hpp"

#include <iostream>
#include <string>

int main()
{
	std::string code = "number x = 5 + 5";
	parser().parse(code);
}