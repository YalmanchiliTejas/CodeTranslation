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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	while(true){
		vector<pair<char,int>> P(5);
		P[0].first='A';
		P[0].second=in();
		P[0].second+=in();
		if(!P[0].second) break;

		P[1].first='B';
		P[1].second=in();
		P[1].second+=in();
		P[2].first='C';
		P[2].second=in();
		P[2].second+=in();
		P[3].first='D';
		P[3].second=in();
		P[3].second+=in();
		P[4].first='E';
		P[4].second=in();
		P[4].second+=in();

		sort(ALL(P),PAIRCOMP(second,>));
		out(P[0].first,P[0].second);
	}
	return 0;
}

