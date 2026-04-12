#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define ford(i, n) for (int i = int(n)-1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define ms(a, x) memset(a, x, sizeof(a))
#define F first
#define S second
#define endl '\n'
#define de(x) cout<<#x<<" = "<<(x)<<endl
#define de2(x,y) cout<<#x<<" = "<<(x) <<' '<< #y<<" = "<<y<<endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
string st;
int K;
int dp[105][4][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>st>>K;
	dp[0][0][1]=1;
	for(int i=0;i<st.size();i++){
		for(int j=0;j<=3;j++){
			for(int k=0;k<=1;k++){
				int up=k?st[i]-'0':9;
				if(j==K) up=0;
				for(int h=0;h<=up;h++){
					dp[i+1][j+(h!=0)][k&&(h==up)]+=dp[i][j][k];
				}
			}
		}
	}
	cout<<dp[st.size()][K][0]+dp[st.size()][K][1];
    return 0;
}