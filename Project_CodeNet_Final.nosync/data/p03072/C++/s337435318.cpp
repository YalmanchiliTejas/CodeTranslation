#include <bits/stdc++.h>
 
using namespace std;
 
#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define For(I,N)   for(int I=1;I<=(N);I++)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)
#define SZ(X) ((int)(X.size()))
#define LG(X) ((int)(X.length()))
#define CL(X) (X).clear()
#define MAXEL(A,B) (*max_element(A,B))
#define MINEL(A,B) (*min_element(A,B))
#define ROPEN(X) freopen(X,"r",stdin)
#define WOPEN(X) freopen(X,"w",stdout)
#define BG(X) (X.begin())
#define EN(X) (X.end())
#define VI vector<int>
#define PII pair<int,int>
 
//cout << fixed << setprecision(20) << p << endl;
 
template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	vector<int>v(n);
	REP(i,n){
		cin>>v[i];
	}
	LL res=0;
  	int h=0;
  	REP(i,n){
  		if(v[i]>=h){
  			res++;
  			h=v[i];
  		}
  	}
  	cout<<res<<endl;
	return 0;
}
