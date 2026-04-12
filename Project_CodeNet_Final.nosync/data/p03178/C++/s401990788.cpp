#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define all(a)                      a.begin(), a.end()
#define F							first
#define S							second
#define pb                          push_back
#define ll							long long
#define index(a)            		order_of_key(a)
#define value(a)					find_by_order(a)
#define count_1 					__builtin_popcount
#define mod(x, m)					((((x) % (m)) + (m)) % (m))
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

ll dp[11111][111][2];
string s;int d;

ll solve(int pos,int m,int t){
	if(pos==s.size())return m==0;
	
	ll& res = dp[pos][m][t];
	
	if(res!=-1)return res;
	res=0;
	
	int mx= (t==1?s[pos]-'0':9);
	
	for(int i=0;i<=mx;i++){
		int nt= (t&&(s[pos]-'0'==i))?1:0;
		res=(res+solve(pos+1,(m+i)%d,nt))%(1000000007);
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout<<setprecision(12);
	memset(dp,-1,sizeof(dp));
	cin>>s>>d;
	cout<<((solve(0,0,1)-1+1000000007LL)%1000000007);
	return 0;
}