#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main() 
{
	while (1) 
	{
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)break;
		map<int, string>s;
		s.insert(pair<int, string>(a + b, "A"));
		cin >> a >> b;
		s.insert(pair<int, string>(a + b, "B"));
		cin >> a >> b;
		s.insert(pair<int, string>(a + b, "C"));
		cin >> a >> b;
		s.insert(pair<int, string>(a + b, "D"));
		cin >> a >> b;
		s.insert(pair<int, string>(a + b, "E"));
		auto p = s.end();
		p--;
		cout << p->second << " " << p->first << endl;
	}
}