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
int n;
vector<int> hgt;
int top = 0;
int ans = 0;

//inputします
void input() {
	cin >> n;
	hgt.resize(n);
	ff(i, 0, n) {
		cin >> hgt[i];
		if (top <= hgt[i]) {
			ans++;
			top = hgt[i];
		}
	}
}

//ライブラリ置き場



//main
int main() {
	input();

	cout << ans << endl;
	return 0;
}