#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
typedef long long ll;
ll mod=1e9+7;
void add(ll &x,ll y){
	x+=y;
	x%=mod;
}
ll toll(string s){
	ll a=0;
	rep(i,s.size()) a=(a*10+s[i]-'0')%mod;
	return a;
}
ll calc(string s,string t){
	ll ret=0;
	int S=s.size(),T=t.size();
	ll p10=1;
	rep(i,S-T+1){
		string sub=s.substr(S-T-i,T);
		ll low=toll(s.substr(S-i)),up=toll(s.substr(0,S-T-i));
		if(t=="0") up--;
		if(sub<t){
			add(ret,up*p10);
		}else if(sub==t){
			add(ret,up*p10+low+1);
		}else{
			add(ret,(up+1)*p10);
		}
		p10=p10*10%mod;
	}
	if(t=="0") ret++;
	return ret;
}
int main(){
	string A,B,C;
	cin>>A>>B>>C;
	ll ret=calc(B,C);
	if(A!="0"){
		int I=A.size()-1;
		while(A[I]=='0'){
			A[I]='9';
			I--;
		}
		A[I]--;
		ret-=calc(A,C);
	}
	cout<<(ret+mod)%mod<<endl;
}