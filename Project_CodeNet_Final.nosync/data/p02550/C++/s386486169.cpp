#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
template <class Q>
void clearQueue(Q & q) {
    q=Q();
}
void solve(){
	int n,x,m;cin>>n>>x>>m;
	vector<int>hold;
	map<int,int>mp;
	int prev=x;
	mp[x]=1;
	hold.push_back(x);int start=-1;
	int i=-1;
	for(i=2;i<=n;i++){
		int curr=(prev*prev)%m;
		if(mp[curr]!=0) {start=curr;break;}
		prev=curr;
		mp[curr]++;
		hold.push_back(curr);
	}
	// cout<<i<<'\n';
	// for(auto x:hold) cout<<x<<" ";
	vector<int>pre;
	pre.push_back(hold[0]);
	for(int j=1;j<hold.size();j++){
		pre.push_back(pre.back()+hold[j]);
	}
	if(i==n+1){
		cout<<pre[pre.size()-1];return;
	}
	int ans=0;int ind=-1;
	for(int i=0;i<hold.size();i++){
		if(hold[i]==start){ind=i;break;}
	}	
	if(ind>0)
	ans+=pre[ind-1];
	//period length:hold.size()-ind
	//ind,ind+perlen,ind+2*perlen....
	int perlen=hold.size()-ind;
	int firstend=ind+perlen-1;
	int cnt=(n-1-firstend)/perlen;
	cnt++;
	if(ind>0)
	ans+=(cnt)*(pre[firstend]-pre[ind-1]);
	else ans+=(cnt)*(pre[firstend]);
	int lastend=firstend+(cnt-1)*perlen;
	int rem=n-1-lastend;
	if(rem==0) ;
	else{
		if(ind>0)
		ans+=pre[ind+rem-1]-pre[ind-1];
		else ans+=pre[ind+rem-1];
	}
	cout<<ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL); 
//#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
}