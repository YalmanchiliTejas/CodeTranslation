#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include<iomanip>

#define i64 int64_t
#define ff(ii,nn,mm) for(int ii=nn;ii<mm;ii++)
#define ffrvs(ii,nn,mm) for(int ii=nn;ii>=mm;ii--)
#define srt(vvv) sort(vvv.begin(),vvv.end())
#define srtrvs(vvv) reverse(vvv.begin(),vvv.end())
#define Graph vector<vector<int>>

i64 inf = 1000000007;
i64 giant = 4000000000000000037;

using namespace std;

i64 cup(i64 xxx, i64 yyy) {//切り上げ
	return (xxx + yyy - 1) / yyy;
}

//メモリ置き場
string s;

//inputします
void input() {
	cin >> s;
}

//ライブラリ置き場

//main
int main() {
	input();
	if (s[0] == s[1] && s[1] == s[2]) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	return 0;
}