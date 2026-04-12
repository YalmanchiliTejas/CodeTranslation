#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define pb push_back
#define ff first
#define ss second
#define BS binary_search
#define m 1000000007

const long long INF=1e18;

template <class A, class B> ostream& operator<<(ostream& os, const pair<A,B> p) {return os << "(" << p.first << "," << p.second << ")";} 

void dprint(string s) {cout << endl;}
template <class T, class... U> void dprint(string s, T t, U... u) 
{int w = s.find(','); cout << "[" << s.substr(0,w) << ": " << t << "] "; dprint(s.substr(w+1, (int)s.size()-w), u...);} 

#define DEBUG 
#ifdef DEBUG
#define dbg(X...) dprint(#X,X)
#else
#define dbg(X...) "KEEP CALM" 
#endif

const int N=100005; // Don't forget to CHANGE this value ACC. TO Q.
long long moduloMultiplication(long long a, 
                            long long b, 
                            long long mod) 
{ 
    long long res = 0; // Initialize result 
  
    // Update a if it is more than 
    // or equal to mod 
    a %= mod; 
  
    while (b) 
    { 
        // If b is odd, add a with result 
        if (b & 1) 
            res = (res + a) % mod; 
  
        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 
  
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
} 
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T=1; 
    //cin>>T;
    while(T--)
    {
        int n;cin>>n;
        int a[n+1];
        int pref[n+1];
        a[0]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        pref[1]=a[1];
        for(int i=2;i<=n;i++){
            pref[i]=pref[i-1]+a[i];
        }
        int ans=0;
        for(int i=2;i<=n;i++){
            ans+=moduloMultiplication(a[i],pref[i-1],m);
            ans=(ans+m)%m;
        }
        cout<<(ans+m)%m;
    }
    return 0;
}