#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

bool isMissing(string word, int number)
{
	if (number % 15 == 0) return word != "FizzBuzz";
	if (number % 3 == 0) return word != "Fizz";
	if (number % 5 == 0) return word != "Buzz";
	return word != to_string(number);
}

int main()
{
	int m, n;
	while (cin >> m >> n, m + n)
	{
		string words[10001];
		list<int> member;

		for (int i = 1; i <= n; i++) cin >> words[i];
		for (int i = 1; i <= m; i++) member.push_back(i);

		auto nowPlayer = member.begin();
		for (int i = 1; i <= n; i++)
		{

			if (isMissing(words[i], i)) nowPlayer = member.erase(nowPlayer);
			else nowPlayer++;
			if (nowPlayer == member.end()) nowPlayer = member.begin();

			if (member.size() == 1) break;
		}

		auto i = member.begin();
		cout << *i;
		for (i++; i != member.end(); i++)
		{
			cout << ' ' << *i;
		}
		cout << endl;
	}

	return 0;
}