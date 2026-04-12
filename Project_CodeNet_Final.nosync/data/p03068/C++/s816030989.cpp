#include<iostream>
#include<string>
using namespace std;

int main() {
	int k, n;
	string s;
	cin >> n >> s >> k;
	char hoge = s.at(k-1);
	for (auto &&i = s.begin(); i < s.end(); i++) {
		if (*i != hoge) {
			*i = '*';
		}
	}
	cout << s<<endl;
}
