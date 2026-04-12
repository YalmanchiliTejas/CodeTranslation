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
#include<memory>
using namespace std;
using namespace std::chrono;
typedef long long int llint;
typedef double lldo;
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
cout<<fixed<<setprecision(20);
cin.tie(0);
ios::sync_with_stdio(false);
*/
const llint mod=1000000007;
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

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int i,j,n,m,bas;cin>>n>>m;
	static llint seg[524288]={0};
	static llint ans[524288];
	for(i=0;i<524288;i++){ans[i]=-big;}
	bas=262144;
	while(bas>0){ans[bas]=0;bas/=2;}
	vector<vector<pair<int,int>>>ivent(n+2);
	for(i=0;i<m;i++){
		int l,r,a;cin>>l>>r>>a;
		ivent[l].pub(mp(l,a));
		ivent[r+1].pub(mp(l,-a));
	}
	for(i=1;i<=n+1;i++){
		for(auto it:ivent[i]){
			bas=262144+it.fir;
			while(bas>1){
				if(bas%2){seg[bas-1]+=it.sec;ans[bas-1]+=it.sec;}
				bas/=2;
				ans[bas]=max(ans[bas+bas],ans[bas+bas+1])+seg[bas];
			}
		}
		//cerr<<ans[1]<<endl;
		ans[262144+i]=ans[1];
		bas=262144+i;
		while(bas>1){
			bas/=2;
			ans[bas]=max(ans[bas+bas],ans[bas+bas+1])+seg[bas];
		}
	}
	cout<<ans[1]<<endl;
	return 0;
}
