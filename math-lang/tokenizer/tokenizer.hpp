#pragma once

#include <vector>
#include <string>
#include <map>

struct token
{
	enum class token_type
	{
		string,
		number,
		unsigned_number,
		char_quote,
		str_quote,
		Not,
		add,
		sub,
		mult,
		divide,
		equal,
		left_parenthesis,
		right_parenthesis,
		left_sq_bracket,
		right_sq_bracket,
		left_cur_bracket,
		right_cur_bracket,
		Or,
		And,
		white_space,
		identifier,
		function,
		unknown,
	};

	std::map<token_type, char> tokens
	{
		{token_type::add, '+'},
		{token_type::sub, '-'},
		{token_type::mult, '*'},
		{token_type::divide, '/'},

		{token_type::And, '&'},
		{token_type::Or, '|'},
		{token_type::equal, '='},

		{token_type::left_cur_bracket, '{'},
		{token_type::right_cur_bracket, '}'},
		{token_type::left_parenthesis, '('},
		{token_type::right_parenthesis, ')'},
		{token_type::left_sq_bracket, '['},
		{token_type::right_sq_bracket, ']'},

		{token_type::str_quote, '"'},
		{token_type::char_quote, '\''},

		{token_type::white_space, ' '},
	};

	token(token_type tokentype) {};

};