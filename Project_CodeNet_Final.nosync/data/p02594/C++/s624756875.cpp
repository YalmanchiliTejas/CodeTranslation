#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(long long i=(a);((a)<(b)?i<=(b):i>=(b));((a)<(b)?++i:--i))
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   cerr<<#x<<": "<<(x)<<endl
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
constexpr int    INF=1e9;
constexpr double EPS=1e-9;
constexpr int    MOD=1e9+7;
template<class Type>
void line(const Type &a){int cnt=0;for(const auto &elem:a){cerr<<(cnt++?' ':'>');cerr<<elem;}cerr<<endl;}

inline void YESNO(bool ans){cout<<(ans?"YES":"NO")<<endl;}
inline void YesNo(bool ans){cout<<(ans?"Yes":"No")<<endl;}
inline void yesno(bool ans){cout<<(ans?"yes":"no")<<endl;}

int main(){
	int x;
	cin>>x;
	
	bool ans=(x>=30);
	
	YesNo(ans);
}