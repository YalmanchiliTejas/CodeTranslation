#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
using namespace std;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
/*
cout<<setprecision(20)
cin.tie(0);
ios::sync_with_stdio(false);
*/
const llint mod=1e9+7;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
llint rui(llint in,int zyo){//inのzyo乗を計算します
	llint ans=1,gen=in;
	for(int h=0;h<30;h++){
		if(zyo&(1<<h)){ans*=gen;ans%=mod;}
		gen*=gen;gen%=mod;
	}
	return ans;
}
int main(void){
	int n,i,j;cin>>n;
	//1～n,晩兵のn+1,さらに晩兵
	vector<int>h(n+3);
	for(i=1;i<=n;i++){cin>>h[i];}h[n+1]=1;
	vector<pair<int,int>>taka(n+1);
	for(i=1;i<=n+1;i++){taka[i-1]=mp(h[i],i);}
	SO(taka);REV(taka);
	vector<bool>mite(n+3);
	vector<int>hi(n+3);//左端を示します
	vector<int>mg(n+3);//左端を示します
	for(i=0;i<n+3;i++){hi[i]=i;mg[i]=i;}
	vector<llint>free(n+3);
	vector<llint>same(n+3);
	vector<llint>when(n+3);//前にいつ見たか
	for(i=0;i<=n;i++){
		int naga=taka[i].fir;
		int ter=taka[i].sec;
		mite[ter]=1;
		
		free[ter]=1;
		same[ter]=0;
		when[ter]=naga;
		if(mite[ter+1]){
			int net=ter+1;
			mg[ter]=mg[net];
			hi[mg[net]]=ter;
			free[net]*=rui(2,when[net]-naga);
			free[net]%=mod;
			llint f=free[ter]*free[net];
			llint s=2*(free[ter]+same[ter])*(free[net]+same[net])-f;
			free[ter]=f%mod;same[ter]=s%mod;when[ter]=naga;
		}
		if(mite[ter-1]){
			//マージします
			int net=hi[ter-1];
			hi[mg[ter]]=net;
			mg[hi[net]]=mg[ter];
			free[net]*=rui(2,when[net]-naga);
			free[net]%=mod;
			llint f=free[ter]*free[net];
			llint s=2*(free[ter]+same[ter])*(free[net]+same[net])-f;
			free[net]=f%mod;same[net]=s%mod;when[net]=naga;
		}
		//cerr<<"free";for(j=1;j<=n+1;j++){cerr<<free[j]<<" ";}cerr<<endl;
		//cerr<<"same";for(j=1;j<=n+1;j++){cerr<<same[j]<<" ";}cerr<<endl;
	}
	cout<<(free[1]+same[1])%mod<<endl;
	return 0;
}
