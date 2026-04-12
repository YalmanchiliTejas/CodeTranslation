#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <cstring>
#include <queue>
#include <sys/time.h>
using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rev(i,n) for(int i=(int)n-1;i>=0;i--)
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SS stringstream
#define bitcount(b) __builtin_popcount(b)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

#define delete(a,n) a.erase(remove(all(a),n),a.end())
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ( (a)/__gcd((a),(b))*(b) )

template<typename T, typename S> vector<T>& operator<<(vector<T>& a, S b) { a.push_back(b); return a; }
template<typename T> void operator>>(vector<T>& a, int b) {while(b--)if(!a.empty())a.pop_back();}
bool isprime(int n){ if(n<2)return false;  for(int i=2;i*i<=n;i++)if(n%i==0)return false;  return true;} 
ll b_pow(ll x,ll n){return n ? b_pow(x*x,n/2)*(n%2?x:1) : 1ll;}
string itos(int n){stringstream ss;ss << n;return ss.str();}
long long v[6],t[6];
/*
#include <ctime>
#define OFFSET (1311436118)
#define RND(a,b) (int)( (unsigned int)xorshift128()%((b)-(a)+1) + (a))

// V[hÍSvfÌzñBÇÁ©ÅêxKÉè`·é±ÆB
unsigned int seed128[4];

// V[hð^¦éÖ
inline void init_xorshift(unsigned int s){
	for (unsigned int i=0;i<4;++i) seed128[i]=s=1812433253U*(s^(s>>30))+i;
}

// 32bitÌ®ð¶¬
inline unsigned int xorshift128(){
	unsigned int *a = seed128;
	unsigned int  t = (a[0]^(a[0]<<11));
	a[0]=a[1]; a[1]=a[2]; a[2]=a[3];
	return( a[3]=(a[3]^(a[3]>>19))^(t^(t>>8)) );
}


int init(int seed){
	timeval a;
	gettimeofday(&a,NULL);
	if(seed == -1)seed = (time(NULL)-OFFSET)*10000+a.tv_usec / 100;
	init_xorshift(seed);
	return seed;
}

int ppp = 0;
int naive(){
	int poge = 0;
	long long w = *min_element(t,t+3);
	for(int i = 0 ; i <= w ; i++){
		rep(j,3)v[j] = t[j];
		rep(j,3) v[j] -= i;
		int tmp = i + (v[0]/3) + (v[1]/3) + (v[2]/3);
		if(poge < tmp){
			poge = tmp;
			ppp = i;
		}
		
	}
	return poge;
}
*/
int naive2(){
	int poge = 0;
	int w = *min_element(t,t+3);
	for(int i = 0 ; i <= min(3,w) ; i++){
		rep(j,3)v[j] = t[j];
		rep(j,3) v[j] -= i;
		int tmp = i + (v[0]/3) + (v[1]/3) + (v[2]/3);
		if(poge < tmp){
			poge = tmp;
		}
		
	}
	return poge;
}
int main(){
	while(cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5]){
		if(v[0] == 0 && v[1] == 0 && v[2] == 0 && v[3] == 0 && v[4] == 0 && v[5] == 0) return 0;

		v[0] += v[3];
		v[1] += v[4];
		v[2] += v[5];
		v[3] = v[4] = v[5] = 0;
		rep(j,3)t[j] = v[j];
		long long i = *min_element(v,v+3);
		rep(j,3) v[j] -= i;
		int ans = i + (v[0]/3) + (v[1]/3) + (v[2]/3);
		ans = max(ans,naive2());
		cout << ans << endl;
		/*if(naive() != ans){
			cout << naive() << " " << ans << endl;
			cout << ppp << " " << *min_element(t,t+3) << endl;
		}*/
	}
}