#pragma once
#include "../tokenizer/tokenizer.hpp"

#include <string>
#include <iostream>

class parser
{
	// only putting this to make it look clean
private:
	std::string code;
	int current_pos;
	tokenizer::token_type current_token;

	void peak()
	{
		current_pos++;
	}
	
	void set_token(tokenizer::token_type token)
	{
		current_token = token;
		tokens.emplace_back(current_token);
	}

	bool is_whitespace()
	{
		if (code[current_pos] == ' ')
			return true;

		return false;
	}

public:

	std::vector<tokenizer::token_type> tokens;

	bool parse()
	{
		while (current_token != tokenizer::token_type::EOF)
		{
			// check if its EOF just in case
			if (code[current_pos] == '\0')
				set_token(tokenizer::token_type::EOF);

			// first check if its an int or string
			if (code[current_pos] == 'n')
			{
				peak();
				if (code[current_pos] == 'u')
				{
					peak();
					if (code[current_pos] == 'm')
					{
						peak();
						if (code[current_pos] == 'b')
						{
							peak();
							if (code[current_pos] == 'e')
							{
								peak();
								if (code[current_pos] == 'r')
								{
									set_token(tokenizer::token_type::number);
									if (is_whitespace())
										peak();
									if (code[current_pos] == '=')
									{
										set_token(tokenizer::token_type::equal);
										peak();
										while (current_token != tokenizer::token_type::EOL)
										{
											
										}
									}
								}
							}
						}
					}
				}
			}


		}
		return true;
	}
	parser() = default;
	~parser() = default;
};