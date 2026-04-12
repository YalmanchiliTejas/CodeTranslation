#include<bits/stdc++.h>
#define fo(i,a,b) for(int i= a ; i < b ; ++i)
#define rep(i,n) fo(i,0,n)
#define pln(n) printf("%lld\n",n)
#define sll(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define dbg3(x,y,z) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) <<" , "<< #z <<": "<<(z)<<endl; }
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define vll vector<long long>
#define vvi vector<vector<int>>
#define si set<int>
#define tr(c, it) \
for(decltype(c.begin()) it = c.begin(); it!= c.end(); it++)
#define pis pair<int,string>
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c),x) != c.end())
#define mod (int)(1e9 + 7) 

using namespace std;
long long dp[3001][3001][2];

int main(){
	int n;
	cin >> n;
	vector<long long> a(n);
	long long S = 0;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		S += a[i];
		dp[i][i][0] = a[i];
		dp[i][i][1] = a[i];
	}
	for(int len = 2; len <= n; len++){
		for(int i = 0; i + len - 1 < n; i++){
			int j = i + len -1;
			if(len == 2){
				dp[i][j][0] = max(a[i], a[j]);
				dp[i][j][1] = max(a[i], a[j]);
			}
			else{
				long long sum = 0;
				for(int ind = i; ind <= j; ind++){
					sum += a[ind];
				}
				// for first player
				dp[i][j][0] = max(sum - dp[i+1][j][1], sum - dp[i][j-1][1]);
				dp[i][j][1] = max(sum - dp[i+1][j][0], sum - dp[i][j-1][0]);
			}
		}
	}
	cout << 2 * dp[0][n-1][0] - S << endl;
	
}