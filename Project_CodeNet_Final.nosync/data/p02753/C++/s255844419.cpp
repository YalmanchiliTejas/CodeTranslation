#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv)
{
	string str; cin >> str;
	char c = str[0];
	bool ok{true};
	for (auto e : str)
	{
		if (e != c)
			ok = false; 
	}
	std::cout << (ok ? "No" : "Yes")<< std::endl;
}
