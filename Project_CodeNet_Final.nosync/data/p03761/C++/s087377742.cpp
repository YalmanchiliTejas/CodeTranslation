#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	auto cnt = vector<vector<int>>(n, vector<int>('z' + 1));
	for(auto i = 0; i < n; ++i){
		string s;
		cin >> s;
		for(auto c : s) ++cnt[i][c];
	}
	auto com = vector<int>('z' + 1, 50);
	for(auto d : cnt){
		for(auto i = (int)'a'; i <= 'z'; ++i){
			com[i] = min(com[i], d[i]);
		}
	}
	for(auto i = 'a'; i <= 'z'; ++i){
		for(auto j = 0; j < com[i]; ++j){
			cout << i;
		}
	}
	cout << endl;
	return 0;
}