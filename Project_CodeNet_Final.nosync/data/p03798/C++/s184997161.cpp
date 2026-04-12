#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define Nmax 200010
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define RFOR(i,a,b) for(long long i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<P> Graph;

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	bool ans[Nmax];
	ans[0]=true;
	if(s[0]=='o') ans[1]=true;
	else ans[1]=false;
	FOR(i,1,N){
		if(s[i]=='o'){
			if(ans[i]) ans[i+1]=ans[i-1];
			else ans[i+1]=!ans[i-1];
		}else{
			if(ans[i]) ans[i+1]=!ans[i-1];
			else ans[i+1]=ans[i-1];
		}
	}
	if(ans[N-1] && (ans[0]==ans[N])){
		REP(i,N){
			if(ans[i]) cout<<"S";
			else cout<<"W";
		}
		return 0;
	}
	
	ans[0]=true;
	if(s[0]=='o') ans[1]=false;
	else ans[1]=true;
	FOR(i,1,N){
		if(s[i]=='o'){
			if(ans[i]) ans[i+1]=ans[i-1];
			else ans[i+1]=!ans[i-1];
		}else{
			if(ans[i]) ans[i+1]=!ans[i-1];
			else ans[i+1]=ans[i-1];
		}
	}
	if(!ans[N-1] && (ans[0]==ans[N])){
		REP(i,N){
			if(ans[i]) cout<<"S";
			else cout<<"W";
		}
		return 0;
	}
	
	ans[0]=false;
	if(s[0]=='o') ans[1]=false;
	else ans[1]=true;
	FOR(i,1,N){
		if(s[i]=='o'){
			if(ans[i]) ans[i+1]=ans[i-1];
			else ans[i+1]=!ans[i-1];
		}else{
			if(ans[i]) ans[i+1]=!ans[i-1];
			else ans[i+1]=ans[i-1];
		}
	}
	if(ans[N-1] && (ans[0]==ans[N])){
		REP(i,N){
			if(ans[i]) cout<<"S";
			else cout<<"W";
		}
		return 0;
	}
	ans[0]=false;
	if(s[0]=='o') ans[1]=true;
	else ans[1]=false;
	FOR(i,1,N){
		if(s[i]=='o'){
			if(ans[i]) ans[i+1]=ans[i-1];
			else ans[i+1]=!ans[i-1];
		}else{
			if(ans[i]) ans[i+1]=!ans[i-1];
			else ans[i+1]=ans[i-1];
		}
	}
	if(!ans[N-1] && (ans[0]==ans[N])){
		REP(i,N){
			if(ans[i]) cout<<"S";
			else cout<<"W";
		}
		return 0;
	}
	
	cout<<-1<<endl;
	return 0;
}