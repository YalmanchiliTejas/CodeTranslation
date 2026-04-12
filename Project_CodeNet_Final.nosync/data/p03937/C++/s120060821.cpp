#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<numeric>
#include<vector>
#include<tuple>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
typedef long long ll;
const int MOD = 1e9 + 7;
string a, b;
int s[8][8];
int main(void)
{
	int H, W,cnt=0;
	cin >> H >> W;
	FOR(i, 0, H) {
		FOR(k, 0, W) {
			char tes;
			cin >> tes;
			if (tes == '#')cnt++;
		}
	}
	if (cnt == H + W - 1)cout << "Possible" << endl;
	else cout << "Impossible" << endl;

	return 0;
}
