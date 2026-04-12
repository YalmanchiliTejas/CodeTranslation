                                                                   //author rhythmicankur
                                                                  //god_is_almighty
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#define f 		first
#define s 		second
#define int     long long
#define ll      int
#define ld 		long double
#define pb 		push_back
#define eb 		emplace_back
#define mk 		make_pair
#define vi 		vector<int>
#define pii 		pair<int,int>
#define pip             pair<int,pii>
#define vpi 		vector<pii>
#define sbcount(x) __builtin_popcountll(x)
#define REP(i,n) for (int i = 1; i <= n; i++)
#define trav(a, x)      for(auto& a : x)
#define all(x)          x.begin(), x.end()
#define fill(a,val)	memset(a,val,sizeof(a))
#define 	PI acos(-1)
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define M1 	998244353
#define M2 	1000000007
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); } 
#define test4(x,y,z,a) 		    cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"  |  "<<#a<<": "<<a<<endl;
#define test1(x)                cerr<<#x<<": "<<x<<endl
#define test2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define test3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
ll power(ll a,ll b,ll m=M2){ll answer=1;while(b){if(b&1)answer=(answer*a)%m;b/=2;a=(a*a)%m;}return answer;}
using namespace std;
void ctrl(){cout<<"Control"<<endl;}
int make_num(string p){stringstream geek(p); int x = 0; geek >> x;return x;}
string make_str(int x){ostringstream str1; str1 << x; string geek = str1.str(); return geek;}
const int N=3000+5;
int dp[N][N][2];
int A[N];
/*int recur(int l,int r,int step)
{
    if(l>r)
    return 0;
    if(l==r)
    return A[l];
    if(r-l==1)
    {
        if(step)
        return max(A[l],A[r]);
        else
        return min(A[l],A[r]);
    }
    if(dp[l][r][step]!=-1)
    return dp[l][r][step];
    int ans;
    if(step)
    {
        ans=max(A[l]+recur(l+1,r,0),A[r]+recur(l,r-1,0));
    }
    else
    {
        ans=min(recur(l+1,r,1),recur(l,r-1,1));
    }
    return dp[l][r][step]=ans;
    

}*/

int recur(int l,int r,int step)
{
    if(l>r)
    return 0;
    if(r-l==1)
    {
        if(step==0)
        return max(A[l],A[r]);
        else
        
        return min(A[l],A[r]);
 
    }

    if(dp[l][r][step]!=-1)
    return dp[l][r][step];

    int ans=0;
    if(step==0)
    ans=max(A[l]+recur(l+1,r,1),A[r]+recur(l,r-1,1));
    else
    ans=min(recur(l+1,r,0),recur(l,r-1,0));

    return dp[l][r][step]=ans;
}
signed main()
{	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin.exceptions(cin.failbit);
	int n;
    cin>>n;
    int s=0;
    for(int i=0;i<n;i++)cin>>A[i],s+=A[i];
    memset(dp,-1,sizeof(dp));
    
    int x = max(A[0]+recur(1,n-1,1),A[n-1]+recur(0,n-2,1));
    //test2(x,s-x);
    cout<<x-s+x;


return 0;
}