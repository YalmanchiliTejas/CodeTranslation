#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define for1(i, m, n) for(int i = m;i < n;i++)
#define ll long long
#define endl '\n'
using namespace std;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    char a[9][9];
    int cnt = 0;
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                cnt++;
            }
        }
    }
    if(cnt == h + w - 1) {
        puts("Possible");
    } else {
        puts("Impossible");
    }
	return 0;
}