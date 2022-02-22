#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <numeric>
#include <algorithm>

class Initial
{
private:
	char letter_;
	Initial() = default;
public:
	Initial(char letter) :letter_(letter) {};
	~Initial() = default;
	bool operator() (std::string& word)
	{
		return word[0] == letter_;
	}
};

class MyStr
{
private:
	std::string string_;
	MyStr() = default;
public:
	MyStr(std::string string):string_(string) {};
	~MyStr() = default;
	friend bool operator == (const MyStr& str1,const MyStr& str2)
	{
		return str1.string_ == str2.string_;
	}
};

int main()
{
	std::ifstream input_file("input.txt");
	std::list<std::string> words;
	std::string word;
	while (input_file >> word)
		words.push_back(word);
	
	words.sort();

	for (std::string word : words)
		std::cout << word << "\n";

	std::cout << "\n";

	char letter = 'l';
	std::list<std::string>::iterator it1 = std::find_if(words.begin(), words.end(), Initial(letter));
	std::list<std::string>::iterator it2 = std::find_if_not(it1, words.end(), Initial(letter));

	for (it1; it1 != it2; ++it1)
		std::cout << *it1 << "\n";
	
	std::cout << "\n";

	words.erase(std::find_if(words.begin(), words.end(), Initial(letter)), std::find_if_not(std::find_if(words.begin(), words.end(), Initial(letter)), words.end(), Initial(letter)));

	for (std::string word : words)
		std::cout << word << "\n";

	std::cout << "\n";

	std::ifstream input_numbers("numbers.txt");
	std::list<int> numbers;
	int number;
	while (input_numbers >> number)
		numbers.push_back(number);

	int num = 2;

	int duplicate = std::count_if(numbers.begin(), numbers.end(), [num](int number)
		{
			return number == num;
		});
	std::cout << "\n";

	int range =  std::count_if(numbers.begin(), numbers.end(), [](int number)
		{
			return number < 3 && number > 0;
		});
	
	float average = std::accumulate(numbers.begin(),numbers.end(),0) / numbers.size();

	/*MyStr str1("string1");
	MyStr str2("string2");
	MyStr str3("string3");
	std::string str = "string1";
	std::list<MyStr> strings {str1,str2,str3};
	int duplicate_string = std::count_if(strings.begin(), strings.end(), [str](std::string string)
		{
			return string == str;
		});
	std::cout << duplicate_string << "\n";*/

	for (int number : numbers)
		std::cout << number << "\n";
}