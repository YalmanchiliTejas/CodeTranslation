#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef pair<int,int> Pi;
typedef long long int ll;
const int INF=(ll)(1<<30)-1;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int n;
string s[55];
int t[55][30];
int ans[30];

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<s[i].size();j++){
			t[i][s[i][j]-'a']++;
		}
	}
	
	for(int i=0;i<26;i++)
		ans[i]=t[0][i];
	for(int j=0;j<26;j++){
		for(int i=1;i<n;i++){
			ans[j]=min(ans[j],t[i][j]);
		}
	}
	string ansi;
	for(int i=0;i<26;i++){
		for(int j=0;j<ans[i];j++){
			ansi+=('a'+i);
		}
	}
	cout<<ansi<<endl;
	return 0;
}