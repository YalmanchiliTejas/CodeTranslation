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
#include<unordered_map>
#include<array>
#include<map>
#include<bitset>
#include<iomanip>
#include<list>
#include <numeric>
using namespace std;
typedef unsigned long long int ulint;
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
#define RE return 0
//ios::sync_with_stdio(false);
//std::cin.tie(0);
//<< setprecision(20)
const int mod=(int)1e9+7;
const llint big=(llint)(2.19e15+1)*18;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
template <class T> void soun(T& ar)
{sort(ar.begin(),ar.end());ar.erase(unique(ar.begin(),ar.end()),ar.end());}
llint gcd(llint a,llint b){if(a%b==0){return b;}else{return gcd(b,a%b);}}
llint lcm(llint a,llint b){return a/gcd(a,b) *b;}
template<class T,class U> auto LB(T& ve,U in){return lower_bound(ve.begin(),ve.end(),in);}
template<class T,class U> auto UB(T& ve,U in){return upper_bound(ve.begin(),ve.end(),in);}
template<class T,class U> auto LBI(T& ve,U in){return LB(ve,in)-ve.begin();}
template<class T,class U> auto UBI(T& ve,U in){return UB(ve,in)-ve.begin();}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
int main(void){
	llint n,a,b,c,d,i,j,k;cin>>n>>a>>b>>c>>d;
	llint kai[1001]={0};
	kai[0]=1;
	for(i=1;i<=1000;i++){kai[i]=(kai[i-1]*i)%mod;}
	//cerr<<"kai[6]="<<kai[6]<<endl;
	llint gya[1001]={0};
	gya[1000]=1;llint bgen=kai[1000];
	for(int h=0;h<30;h++){
		if((mod-2)&(1<<h)){gya[1000]*=bgen;gya[1000]%=mod;}
		bgen*=bgen;bgen%=mod;
	}
	for(i=999;i>0;i--){gya[i]=gya[i+1]*(i+1)%mod;}
	//cerr<<"gya[1]="<<gya[1]<<endl;
	llint dp[1001]={0};dp[0]=kai[n];
	for(i=a;i<=b;i++){
		llint ddp[1001]={0};
		llint rui[1001]={0};rui[0]=1;
		for(k=1;k<=d;k++){rui[k]=rui[k-1]*gya[i]%mod;}
		for(k=1;k<=d;k++){rui[k]*=gya[k];rui[k]%=mod;}
		for(j=0;j<=n;j++){
			for(k=c;k<=d;k++){
				int ter=j+k*i;if(n<ter){break;}
				ddp[ter]+=dp[j]*rui[k];
				ddp[ter]%=mod;
			}
		}
		for(j=0;j<=n;j++){dp[j]+=ddp[j];dp[j]%=mod;}
	}
	cout<<dp[n]<<endl;RE;
}
