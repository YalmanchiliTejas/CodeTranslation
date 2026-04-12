#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cctype>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define len(s) s.length()
#define forp(i,a,b) for( i=a;i<=b;i++)
#define rep(i,n)    for( i=0;i<n;i++)
#define ren(i,n)    for( i=n-1;i>=0;i--)
#define forn(i,a,b) for( i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#define b(v) v.begin()
#define e(v) v.end()
#define mem(n,m) memset(n,m,sizeof(n))
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define gl(cin,s)  getline(cin,s);
#define bitc(n) __builtin_popcountll(n)
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define boost ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define SIZE 3010
#define SZ 1010

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int N;
int A[SIZE];
long long dp[SIZE][SIZE][2];
long long func(int lft,int rgt, int whose)
{
    if(lft > rgt)
        return 0;
    if(dp[lft][rgt][whose] != LLONG_MIN)
        return dp[lft][rgt][whose];
    long long fans;
    if(whose){
        fans = LLONG_MAX;
        fans = min(fans,-1*A[lft] + func(lft+1,rgt,1-whose));
        fans = min(fans,-1*A[rgt] + func(lft,rgt-1,1-whose));
    }
    else{
        fans = LLONG_MIN;
        fans = max(fans,A[lft] + func(lft+1,rgt,1-whose));
        fans = max(fans,A[rgt] + func(lft,rgt-1,1-whose));
    }
    dp[lft][rgt][whose] = fans;
    return fans;
}
int main()
{
    /* #ifndef ONLINE_JUDGE
    freopen(fi, "r", stdin);
    #endif */
    //freopen("route.in","r",stdin);
    //freopen("route.out","w",stdout);
    //cin.ignore();
    //cin.clear();
    boost;
    //cin.tie(0);
    //cout<<"Case "<<tt<<": ";
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            dp[i][j][0] = LLONG_MIN;
            dp[i][j][1] = LLONG_MIN;
        }
    }
    cout<<func(1,N,0)<<endl;
    return 0;
}