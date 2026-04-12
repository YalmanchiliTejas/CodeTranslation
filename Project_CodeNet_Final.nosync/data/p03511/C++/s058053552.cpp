#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

using namespace std;
ll L;
string S[2];
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>L;
	REP(i,2)cin>>S[i];
	ll cnt[2],len[2];
	REP(i,2)len[i]=S[i].size(),cnt[i]=0;
	ll l=lcm(len[0],len[1]);
	ll ooi=0;
	if(l<=L){
		string t[2];
		REP(i,2){
			t[i]="";
			REP(j,l/len[i]){
				t[i]+=S[i];
			}
		}
		if(t[0]>t[1]){
			ooi=1;
		}
	}
	ll suk=1-ooi;
	REP(i,L+1){
		if(L-i*len[ooi]>=0 && (L-i*len[ooi])%len[suk]==0){
			cnt[ooi]=i;
			cnt[suk]=(L-i*len[ooi])/len[suk];
		}
	}
	ll saki=0;
	if(S[0]+S[1]>S[1]+S[0]){
		saki=1;
	}
	REP(i,cnt[saki]){
		cout<<S[saki];
	}
	REP(i,cnt[1-saki]){
		cout<<S[1-saki];
	}
	cout<<endl;
}