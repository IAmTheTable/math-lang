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
		{
			set_token(tokenizer::token_type::white_space);
			return true;
		}

		return false;
	}

	bool is_number()
	{
		// shorter for this massive if statement
		auto x = code[current_pos];
		if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8 || x == 9 || x == 0)
			return true;
		else return false;
	}

public:

	std::vector<tokenizer::token_type> tokens;

	std::map<std::string, void*> variables;

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

									std::string var_name;
									while (current_token != tokenizer::token_type::white_space)
									{
										if (!is_whitespace())
											var_name += code[current_pos];

										peak();
									}

									set_token(tokenizer::token_type::identifier);

									if (code[current_pos] == '=')
									{
										set_token(tokenizer::token_type::equal);

										peak();

										if (is_number())
										{
											// now chck whats on the other side of number x = (expr)
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