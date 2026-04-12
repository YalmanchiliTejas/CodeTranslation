#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<chrono>
#include<functional>
#include<iterator>
//#include<random>
#include<unordered_set>
#include<map>
using namespace std;
typedef long long int llint;
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
const int mod=1000000007;
const llint big=1e18+10;
const long double pai=3.141592653589793238462643383279;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
int gcd(int a,int b){if(a%b==0){return b;}else return gcd(b,a%b);}//a>b
int main(void){
	llint i,j,n,wa=0;cin>>n;//
	vector<llint>a(n);
	for(i=0;i<n;i++){cin>>a[i];wa+=a[i];}
	llint ans=max((llint)0,wa-10000);
	while(-1){
		llint now=0;
		for(i=0;i<n;i++){
			now+=max((llint)0,(a[i]+ans+1)/(n+1));
		}
		if(now<=ans){cout<<ans<<endl;return 0;}//足りる
		ans++;
	}
	return 0;
}
