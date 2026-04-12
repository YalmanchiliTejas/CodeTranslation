#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
int num(char t) {
	if (t == 'T')return 10;
	if (t == 'J')return 11;
	if (t == 'Q')return 12;
	if (t == 'K')return 13;
	if (t == 'A')return 14;
	return t - '0';
}
int main() {
	char trump;
	while (cin >> trump) {
		if (trump == '#')break;
        string card[4][13];
		rep(i, 4) {
			rep(j, 13) {
				cin >> card[i][j];
			}
		}
		int cnt[4] = {};
		char suit=card[0][0][1];
		rep(i, 13) {
			int chk = -1; int ma = -1;
			rep(j, 4) {
				if (card[j][i][1] == trump) {
					if (ma < num(card[j][i][0])) {
						ma = num(card[j][i][0]);
						chk = j;
					}
				}
			}
			if (chk >= 0) {
				cnt[chk]++;
				if (i < 12) {
					suit = card[chk][i + 1][1];
				}
				continue;
			}
			rep(j, 4) {
				if (card[j][i][1] == suit) {
					if (ma < num(card[j][i][0])) {
						ma = num(card[j][i][0]);
						chk = j;
					}
				}
			}
			cnt[chk]++;
			if (i < 12) {
				suit = card[chk][i + 1][1];
			}
		}
		int a = cnt[0] + cnt[2];
		int b = cnt[1] + cnt[3];
		if (a > b) {
			cout << "NS " << a - 6 << endl;
		}
		else {
			cout << "EW " << b - 6 << endl;
		}
	}
	return 0;
}
