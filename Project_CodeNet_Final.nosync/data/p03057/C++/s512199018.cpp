#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
int m;
string s;
int mn = INF;
ll ans ;
ll dp[200005][2][2];

struct RMQ{
	#define ss (1<<19)
	ll seg[ss];
	void update(int k,ll a){
		k+=ss/2-1; seg[k]=a;
		while(k>0){
			k=(k-1)/2;
			seg[k]=(seg[k*2+1]+seg[k*2+2])%mod;
		}
	}
	ll query(int a,int b,int k,int l,int r){
		if(r<a || b<l) return 0;
		if(a<=l && r<=b) return seg[k];
		else{
			ll vl=query(a,b,k*2+1,l,(l+r)/2);
			ll vr=query(a,b,k*2+2,(l+r)/2+1,r);
			return (vl+vr)%mod;
		}
	}
}rmq[2];

int main(){
	cin>>n>>m>>s;
    	if(s[0] == 'B'){
    		rep(i,m){
    			if(s[i] == 'B') s[i] = 'R';
    			else s[i] = 'B';
    		}
    	}
		int cur = 0;
		char ch;
		bool beg = 0;
		int C = 0;
		rep(i,m){
			if(i == 0){
				ch = s[i];
				cur = 1;
			}
			else if(ch != s[i]){
				if(ch == 'R'){
					if(cur%2 == 1) mn = min(mn,cur);
					else if(!beg) mn = min(mn,cur+1);
					beg = 1; 
				}
					ch = s[i];
					cur = 1; C++;
				
			}
			else cur++;
		}
				if(ch == 'R'){
					/*if(cur%2 == 1) mn = min(mn,cur);
					else if(!beg) mn = min(mn,cur+1);
					beg = 1; */
				}
				C++;
				
		if(C == 1){
			//BBが存在しなければOK
			dp[0][0][0] = dp[0][1][1] = 1;
			for(int i=0;i<n-1;i++){
				rep(x,2){
					dp[i+1][0][x] += dp[i][0][x];
					dp[i+1][1][x] += dp[i][0][x];
					dp[i+1][0][x] += dp[i][1][x];
					dp[i+1][0][x] %= mod;
					dp[i+1][1][x] %= mod;
				}
			}
			cout<<((dp[n-1][0][0]+dp[n-1][0][1]+dp[n-1][1][0])%mod+mod)%mod<<endl;
		}
		else{
			dp[0][0][0] = 1;
			rmq[0].update(0,1);
			for(int i=2;i<n;i+=2){
				dp[i][0][0] = rmq[i%2].query(max(0,i-mn-1),i,0,0,(1<<18)-1);
				rmq[i%2].update(i,dp[i][0][0]);
			}
			ll ans = 0;
			for(int m=1;m<=n;m++){
				if(m-1 > mn) continue;
				if((m-1)%2 == 0) continue;
				ans += dp[n-m][0][0] * 1LL * m % mod;
			}
			cout << (ans%mod+mod)%mod << endl;
		
		}
	
}