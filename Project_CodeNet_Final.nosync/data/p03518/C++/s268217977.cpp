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
#define RE return 0
//ios::sync_with_stdio(false);
//std::cin.tie(0);
//<< setprecision(20)
const int mod=1e9+7;
const int big=1e9+100;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
template <class T> void soun(T& ar)
{sort(ar.begin(),ar.end());ar.erase(unique(ar.begin(),ar.end()),ar.end());}
int main(void){
	int i,n,j;cin>>n;
	vector<int>in(n);
	for(i=0;i<n;i++){cin>>in[i];}
	vector<int>kou;
	while(-1){
		kou.pub(1);
		for(j=0;j<n-1;j++){
			if(in[j]>in[j+1]){swap(in[j],in[j+1]);kou.pub(n-1);}
			kou.pub(1);
		}
		int ok=1;
		for(j=0;j<n;j++){
			if(in[j]!=j){ok=0;break;}
		}
		if(ok){break;}
	}
	cout<<kou.size()<<endl;
	for(auto it:kou){cout<<it<<endl;}
	RE;
}