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

	string S=in<string>();
	int N=S.size();
	int K=in();

	// dp[i][j][k]: 上からi桁目までを取り出した時、すでに0ではない数がk個ある場合の数
	vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(2,vector<ll>(K+1,0)));
	dp[0][0][0]=1;
	REP(i,N){
		ll digit = S[i]-'0';
		for(int smaller=0;smaller<2;smaller++){
			for(int j=0;j<K+1;j++){
				for(int x=0;x<=(smaller?9:digit);x++){
					if(x==0){
						dp[i+1][smaller || x<digit][j]+=dp[i][smaller][j];
					}
					else{
						if(j+1<=K) dp[i+1][smaller || x<digit][x>0?j+1:j]+=dp[i][smaller][j];
						//else dp[i+1][smaller || x<digit][K]+=dp[i][smaller][j];
					}
				}
			}
		}
	}

	out(dp[N][0][K]+dp[N][1][K]);
	return 0;
}
