#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define LOOP(i) while(i--)
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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	ll N=in();
	auto V=vecin<ll>(N);
	sort(ALL(V),greater<ll>());
	vector<ll> C(N);
	if(N%2){
		int even = N/2;
		int odd = N-even;
		REP(i,odd-2){
			C[i] = 2;
		}
		C[odd-2]=C[odd-1]=1;
		for(int i=odd;i<N;i++){
			C[i] = -2;
		}
	}
	else{
		int even = N/2;
		int odd = N-even;
		REP(i,odd-1){
			C[i] = 2;
		}
		C[odd-1]=1;
		C[odd]=-1;
		for(int i=odd+1;i<N;i++){
			C[i] = -2;
		}
	}
	int left=0,right=N-1;
	ll sum1=0;
	while(C[left]>0){
		sum1 += C[left]*V[left];
		left++;
	}
	while(C[right]<0){
		sum1 += C[right]*V[right];
		right--;
	}
	ll sum2=0;
	left=0,right=N-1;
	while(C[left]>0){
		sum2 -= C[left]*V[N-1-left];
		left++;
	}
	while(C[right]<0){
		sum2 -= C[right]*V[N-1-right];
		right--;
	}

	out(max(sum1,sum2));
	return 0;
}
