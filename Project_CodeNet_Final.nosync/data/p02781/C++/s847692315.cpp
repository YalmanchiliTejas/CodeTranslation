#include <bits/stdc++.h>
//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//~ using namespace __gnu_pbds; 
#define mp make_pair
#define endl '\n'
typedef long long ll;
 
const int INF=1e9+5;
const ll lim=(ll)3e16;
const int N=1e6+5;
const int mod=1e9+7;	
const ll oo=1e18+5;

//~ typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	string s;
	int k;
	cin>>s>>k;
	int n=(int)s.size();
	vector<vector<vector<ll>>> dp(n+5,vector<vector<ll>>(k+5,vector<ll>(2)));
	dp[0][0][0]=1;
	for(int i=0;i<n;++i){
		for(int j=0;j<2;++j){
			for(int cnt=0;cnt<k+1;++cnt){
				int pre_num;
				if(j) pre_num=9;
				else pre_num=s[i]-'0';
				for(int dig=0;dig<=pre_num;++dig){
					dp[i+1][cnt+(dig!=0)][j||dig<pre_num]+=dp[i][cnt][j];
				}
			}
		}
	}
	cout<<dp[n][k][0]+dp[n][k][1];
	return 0;	
}
