// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <locale>
#include <cctype>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define MP make_pair
#define fastIO	cin.tie(0); ios::sync_with_stdio(false);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
//for gcc (未test)
// #define FOREACH_IT(it,c)	for(typeof(c)::iterator it=(c).begin(); it!=(c).end(); ++it)
//for Visual Studio
#define foreach_it(type,it,c) for(type::iterator it=c.begin(); it!=c.end(); ++it)

void solveAndOutput(vector<pair<char, int> > list){
	int max = -1;
	char ansShopName = 'F';
	FOR(i, 0, list.size()){
		if (max < list[i].second){
			max = list[i].second;
			ansShopName = list[i].first;
		}
	}
	cout << (char)ansShopName << " " << max << endl;
}

int main(){
	int s1, s2, count = 0;
	char shopName = 'A';
	vector<pair<char, int> > list;
	fastIO;
	// s1&&s2ではWrongAnswerだった.販売個数に0が含まれているのでは...？
	while (cin >> s1 >> s2, s1||s2){
		list.push_back(MP(shopName + count, s1 + s2));
		count++;
		if (count == 5){
			solveAndOutput(list);

			list.clear();
			count = 0;
			shopName = 'A';
		}
	}
	return 0;
}