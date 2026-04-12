//#pragma GCC optimize "trapv"
//-D_GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define pm(m) for(auto itr=(m).begin();itr!=(m).end();itr++){itr->first<<" "<<itr->second<<"\n";}
#define int long long int
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define ii pair<int,int>
#define Max 100000+5
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f first
#define s second
#define pb push_back
#define bug(x) cout<<(x)<<" ";exit(0);
int mod = 1000000007;
int mod1 = 998244353;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dis(string s, string t){
    int val=0;
    for(int i=0;i<t.length();i++){
        if(s[i]!=t[i])val++;
    }
    return val;
}
int32_t main(){
	IO
	//freopen("input.txt","r",stdin);
    	//freopen("output.txt","w",stdout);
	
	int n;
	cin>>n;
	vector<int> v(n),p(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	for(int i=n-1;i>=0;i--){
	    p[i] = ((i==n-1)?v[i]:v[i]+p[i+1]);
	    if(p[i]>mod)p[i]%=mod;
	}
	int ans=0;
	for(int i=0;i<n-1;i++){
	    ans+= (v[i]*p[i+1])%mod;
	    ans%=mod;
	}
	cout<<ans;
	
}