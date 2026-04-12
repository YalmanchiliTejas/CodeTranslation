#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;
//for debugging 
/*
g++ -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -std=c++14 
*/
int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}
// debugging ends here
 
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void solve(){
	string n;
	int k;
	cin >> n >> k;
	int len = n.length();
	int dp[len+1][5];
	memset(dp,0LL,sizeof(dp));
	int cur = 0;
	for(int i =1;i<=len;i++){
		for(int j = 0;j<n[i-1]-'0';j++)
			dp[i][min(cur+(j!=0),4)]+=1;
 
		for(int j =0;j<=k;j++)
		{
			dp[i][j]+=dp[i-1][j];
			dp[i][j+1] +=dp[i-1][j]*9;
		}
		cur+=(n[i-1]!='0');
	}
	if(cur==k)
		dp[len][k]++;
	cout << dp[len][k] << endl;
}
 
int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
 
	// int t;cin >> t;while(t--)
		solve();
}