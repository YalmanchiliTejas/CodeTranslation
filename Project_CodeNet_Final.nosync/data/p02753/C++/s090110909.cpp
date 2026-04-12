/*
ID: wangjun30
LANG: C++11
TASK:
*/
#include<iostream>
#include<algorithm>
#include<array>
#include<unordered_map>
#include<map>
#include<set>
#include<list>
#include<unordered_set>
#include<vector>
#include<bitset>
#include<queue>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
//#include<fstream>
#define int long long
using namespace std;
//ifstream cin(".in");
//ofstream cout(".out");
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	cin>>str;
	if(str[0]==str[1] && str[1]==str[2])
		cout<<"No";
	else
		cout<<"Yes";
	return 0;
}