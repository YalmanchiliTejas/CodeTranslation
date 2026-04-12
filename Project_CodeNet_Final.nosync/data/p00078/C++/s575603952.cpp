#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;
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

class Data{
public:
	int u,v,w;
	Data()=default;
	Data(int U,int V,int W):u(U),v(V),w(W){}
};

int main(){
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	while(true){
		int N=in();
		if(!N) break;

		vector<vector<int>> M(N,vector<int>(N,0));
		queue<Data> Q;
		Q.emplace(N/2,(N/2)+1,1);
		while(!Q.empty()){
			auto p=Q.front();
			Q.pop();
			int u=p.u,v=p.v;
			if(u>=N){
				Q.emplace(0,v,p.w);
			}
			else if(u<0){
				Q.emplace(N-1,v,p.w);
			}
			else if(v>=N){
				Q.emplace(u,0,p.w);
			}
			else if(!M[v][u]){
				M[v][u] = p.w;
				if(p.w==N*N) break;
				Q.emplace(u+1,v+1,p.w+1);
			}
			else{
				Q.emplace(u-1,v+1,p.w);
			}
		}
		
		REP(i,N){
			REP(j,N){
				printf("%4d",M[i][j]);
			}
			out();
		}
	}
	return 0;
}
