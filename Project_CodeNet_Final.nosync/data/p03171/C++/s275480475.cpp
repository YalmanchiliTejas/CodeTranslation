#include <bits/stdc++.h>
using namespace std;

#define fori(i,a,b)    for(int i=a;i<=b;i++)
#define ford(i,a,b)   for(int i=a;i>=b;i--)
#define all(a)        a.begin(), a.end()
#define in(c,x)       ((c).find(x) != (c).end())
#define isp(c,x)      (find(all(c),x) != (c).end())
#define pb             push_back
#define ppb            pop_back
#define sz(x)          (int)x.size()
#define fill(a,v)      memset(a, v, sizeof a)
#define fs first
#define sc second
#define ub upper_bound
#define lb lower_bound
#define en '\n'

typedef long long int lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef pair< int, int > pii;
typedef pair< lli, lli > plli;
typedef list<int> li;
typedef map<int, int> mi;
typedef map<lli, lli> mlli;
lli gcd(lli a,lli b){return (!b)?a:gcd(b,a%b);}
//int t = 1; int ti;



const int N = 3e3 + 5;
lli a[N], mem[N][N], n;

lli rec(int l, int r){
    if(l > r)
    return 0;
    
    if(l == r)
    return a[l];

    if(mem[l][r] != -1)
    return mem[l][r];

    lli ans;

    ans = a[r] + min(rec(l, r-2) - a[r-1], rec(l+1, r-1) - a[l]);
    ans = max(ans, a[l] + min(rec(l+1, r-1) - a[r], rec(l+2, r) - a[l+1]));

    return mem[l][r] = ans;
}

void solve(){
    cin>>n;

    fori(i, 1, n)
    cin>>a[i];

    fill(mem, -1);

    cout<<rec(1, n);    
}
//THINK OF SPECIAL CASES, ARRAY LIMITS, LLI vs INT, 1LL

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cin>>t;

    // for(ti= 1; ti <= t; ti++)
    solve();

//    cout<<"\nTHINK OF SPECIAL CASES, ARRAY LIMITS, LLI vs INT, 1LL";
}