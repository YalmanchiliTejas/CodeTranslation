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
#include<list>
#include<bitset>
#include<stack>
#include<memory>
#include<numeric>
using namespace std;
using namespace std::chrono;
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
#define REP(i, n) for(int i = 0;i < (n);i++)
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
const llint mod=1000000007;
const llint inf=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-10;
template <class T,class U>bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(const vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(const vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	llint i,n,ans=0;cin>>n;
	array<llint,6>dp={0,-inf,-inf,-inf,-inf,-inf};
	
	//前に選ない -0 -1 -2
	//前に選んだ -0 -1 -2
	
	for(i=0;i<n;i++){
		llint a;cin>>a;
		array<llint,6>ep;
		ep[0]=dp[3];
		ep[1]=max(dp[0],dp[4]);
		ep[2]=max(dp[1],dp[5]);
		ep[3]=dp[0]+a;
		ep[4]=dp[1]+a;
		ep[5]=dp[2]+a;
		dp=ep;
	}
	if(n%2==1){cout<<max(dp[1],dp[5])<<endl;}
	else{cout<<max(dp[0],dp[4])<<endl;}
	return 0;
}
