#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cerr<<' ';cerr<<elem;}cerr<<endl;}

inline void YESNO(bool ans){cout<<(ans?"YES":"NO")<<endl;}
inline void YesNo(bool ans){cout<<(ans?"Yes":"No")<<endl;}
inline void yesno(bool ans){cout<<(ans?"yes":"no")<<endl;}

int main(){
	int x;
	cin>>x;
	
	bool ans=false;
	if(x>=30) ans=true;
	
	YesNo(ans);
}