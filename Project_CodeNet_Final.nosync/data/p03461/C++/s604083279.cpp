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
const llint big=(llint)44e12;//ごめん
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
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
	int A,B,i,j,x,y;cin>>A>>B;
	int d[11][11]={0};
	int mydis[11][11]={0};
	int ans[101][101]={0};
	for(i=1;i<=A;i++){
		for(j=1;j<=B;j++){cin>>d[i][j];mydis[i][j]=9999;}
	}
	for(i=0;i<=100;i++){for(j=0;j<=100;j++){ans[i][j]=-1;}}
	for(x=0;x<=100;x++){
		for(y=0;y<=100;y++){
			//この数でやってみる
			int gen=-1;
			for(i=1;i<=A;i++){
				for(j=1;j<=B;j++){
					maxeq(gen,d[i][j]-x*i-y*j);
				}
			}
			if(gen<0){continue;}
			ans[x][y]=gen;
			for(i=1;i<=A;i++){
				for(j=1;j<=B;j++){
					mineq(mydis[i][j],gen+x*i+y*j);
				}
			}
		}
	}
	for(i=1;i<=A;i++){
		for(j=1;j<=B;j++){
			if(mydis[i][j]!=d[i][j]){cout<<"Impossible"<<endl;RE;}
		}
	}
	cout<<"Possible"<<endl;
	vector<tuple<int,int,int>> ret;
	int use=3;
	for(x=0;x<=100;x++){
		for(y=0;y<=100;y++){
			if(ans[x][y]==-1){continue;}
			ret.pub(mt(1+x,102+y,ans[x][y]));
		}
	}
	cout<<"202 "<<ret.size()+200<<endl;
	for(x=0;x<100;x++){cout<<x+1<<" "<<x+2<<" X"<<endl;}
	for(y=0;y<100;y++){cout<<y+103<<" "<<y+102<<" Y"<<endl;}
	for(auto it:ret){cout<<get<0>(it)<<" "<<get<1>(it)<<" "<<get<2>(it)<<endl;}
	cout<<"1 102"<<endl;
	RE;
}
