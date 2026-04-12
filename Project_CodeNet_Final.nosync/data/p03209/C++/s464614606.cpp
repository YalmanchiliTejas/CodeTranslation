#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

vector<ll> T,P;
ll dfs(int N,ll end){
	if(N==0) return 1LL;

	ll M=T[N]/2LL+1LL;

	ll V=0;
	if(end>M){
		V += P[N-1]+1LL;
		V += dfs(N-1,end-M);
	}
	else if(end==M){
		V += P[N-1]+1LL;
	}
	else if(end>1){
		V += dfs(N-1,end-1);
	}
	return V;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	ll N=in(),X=in<ll>();
	T.resize(51,0);
	P.resize(51,0);
	T[0]=1,P[0]=1;
	REP(i,50){
		T[i+1] = 2LL*T[i]+3LL;
		P[i+1] = 2LL*P[i]+1LL;
	}
	out(dfs(N,X));
	return 0;
}
