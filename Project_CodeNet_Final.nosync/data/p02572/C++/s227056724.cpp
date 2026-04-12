#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
const int MOD=1e9+7;
int ans,sum;
signed main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		ans+=sum*a;
		sum+=a;
		ans%=MOD;
		sum%=MOD;
	}
	cout<<ans;
	re 0;
}