/* author   : mpily :-()
title : Competing.cpp
time :Sat May 16 10:36:41 2020

*/
#include<bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9+7;

int main(){
	string s;
	cin >> s;
	map<char,int>j;
	for(auto a : s)
		j[a]++;
	if(j['A'] && j['B'])
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}