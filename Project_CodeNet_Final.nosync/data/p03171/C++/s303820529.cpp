#include<bits/stdc++.h>
using namespace std;
#define forn(i, n)             for(int i = 0; i < n; i ++)
#define forn1(i, n)            for(int i = 1; i <= n; i ++)
#define loop(i, sta, end, inc) for(int i = sta; i <= end; i += inc)
#define itr(it, l)             for(auto it = l.begin(); it != l.end(); it ++)
#define in(a, b, c)            assert( b <= a && a <= c)
#define pb push_back
#define ll long long int
#define fi first
#define se second
#define ii  pair<long long int, long long int>
#define vi  vector <long long int>
#define vii vector <pair <long long int, long long int > >
#define all(cont)  cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define what_is(x) cerr<<#x<<" ="<<x<<" ";
#define error(args...)  { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define LINT_MAX  9223372036854775807
#define LINT_MIN -9223372036854775808
#define EPS 1e-9
#define MOD 1000000007
#define DEBUG 0

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
void err(istream_iterator<string> it) { cerr<<endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    if(DEBUG == 0)return;
	cerr << *it << " = " << a <<" ";
	err(++it, args...);
}

long long A[3000];
long long dp[3000][3000];
int main(){
   // freopen("test.txt", "r", stdin);
    int n;cin>>n;
    forn(i,n)cin>>A[i];
    forn(k,n){
    	forn(i,n-k){
    		if(i==i+k)dp[i][i]=A[i];
    		else dp[i][i+k]=max(A[i]-dp[i+1][i+k],A[i+k]-dp[i][i+k-1]);
    	}
    }
    cout<<dp[0][n-1]<<endl;
    
    return 0;
}

