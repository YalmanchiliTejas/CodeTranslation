#pragma comment(linker, "/STACK: 2000000")
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define double long double
#define x first
#define y second
#define pi pair <int, int>
#define vi vector <int>
#define L nod<<1
#define R ((nod<<1)|1)
#define int ll
const ll mod = 1000000007;
string s;
int k, dp[101][5][2];//0 - < n, 1 = n

int32_t main(){
	ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin>>s>>k;
	int n=s.size();
	dp[0][0][1]=1;
	for(int i=1; i<=n; i++){
		char cur=s[i-1];
		for(char nxt='0'; nxt<='9'; nxt++){
			for(int kk=0; kk<=k; kk++){
				for(int ctrl=0; ctrl<=1; ctrl++){
					if(!(ctrl==1 && nxt>cur)) dp[i][kk+(nxt!='0')][((ctrl==1 && nxt==cur) ? 1 : 0)]+=dp[i-1][kk][ctrl];
				}
			}
		}
	}
	cout<<dp[n][k][0]+dp[n][k][1];
}
