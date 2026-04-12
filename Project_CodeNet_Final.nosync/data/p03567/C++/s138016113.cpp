#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long unsigned int llui;
typedef long long int lli;
typedef long double float64;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-9
#define DEBUG(x) cout<< '>' << #x << ':' << x << "\n";
#define all(x) (x).begin(), (x).end()
#define SORT(x) sort((x).begin(),(x).end())
#define UNIQUE(x) (x).erase(unique((x).begin(),(x).end()),(x).end())
#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 

// #define sz(a) int((a).size())
// #define pb push_back
// #define fill(a,v) memset(a,v,sizeof a)


#define trace(x) cout << '>' << #x << ':' << x << endl;
#define trace2(x,y) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y << endl;

#define trace3(x,y,z) cout<< '>' << #x << ':' << x \
        << " | " << #y << ':' << y <<" | " << #z << ':' << z << endl;

#define trace4(x,y,z,w) cout<< '>' << #x << ':' << x \
    << " | " << #y << ':' << y <<" | " << #z << ':' << z << " | " << #w << ':' << w << endl;


inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

#define LSOne(S) (S&(-S))

const double pi = acos(-1);

/////////////////////////////////////////////////////////////////////

/*bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}*/

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; } // __gcd(0,0) gives exception

const int MAX_N = 212345;

int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]=='A' && s[i+1]=='C')
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
