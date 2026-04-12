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
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
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
llint solve(llint n,llint K){
	llint i;
	if(K>n){
		llint ans=1;
		while(n--){ans*=2;ans%=mod;}
		return ans;
	}
	//円環上にAマークとBマーク
	//BマークがKこ連続してはいけない
	vector<llint>dp(n+1);//最後のAマーク
	llint gen=1;//くぎりてん
	dp[0]=1;//最後のBマーク
	for(i=1;i<n;i++){
		dp[i]=gen;
		gen*=2;
		if(i-K>=0){gen-=dp[i-K];}
		gen+=mod;gen%=mod;
	}
	llint ans=0;
	for(i=1;i<=K;i++){
		ans+=i*dp[n-i];
		ans%=mod;
	}
	return ans;
}
int main(void){
	int i,n,m;cin>>n>>m;
	string S;cin>>S;
	vector<int>suu;
	char now=S[0];
	int ban=0;
	for(i=0;i<m;i++){
		if(S[i]==now){ban++;}
		else{suu.pub(ban);ban=1;}
		now=S[i];
	}
	suu.pub(ban);
	//for(auto it:suu){cerr<<it<<endl;}
	if(suu.size()==1){
		cout<<solve(n,2)<<endl;
		return 0;
	}
	if(n%2==1){cout<<0<<endl;return 0;}
	int sei=suu[0];
	if(suu[0]%2==0){sei=suu[0]+1;}
	for(i=2;i+1<suu.size();i+=2){
		if(suu[i]%2==1){mineq(sei,suu[i]);}
	}
	sei++;
	//cerr<<sei<<endl;
	cout<<(2*solve(n/2,sei/2))%mod<<endl;
	return 0;
}