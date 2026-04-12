#include <bits/stdc++.h>      
using namespace std;            

#define    int               long long int
 #define    bp(x)         __builtin_popcount(x)
#define  ld         long double
 #define  f(i,j,n)            for(int i = j; i <= n; i++)
#define  r(i,n,j)       for(int i = n; i >= j; i--)
 #define  all(container)       container.begin() , container.end()
#define  sz(container)   (int)container.size()
 #define  ff             first
#define  ss             second
 #define  pii      pair <int , int>
#define  sp(x)       setprecision(x)
#define  mod   998244353
#define  endl  "\n"
 #define  pb    push_back
#define  mp    make_pair
 #define  T     int ttt; cin >> ttt; while(ttt--)
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int vis[100005];
deque<int>v;
int32_t main()
{
    fast
    int n,ini,m;  cin>>n>>ini>>m;
    vis[ini] = 1;
    v.pb(ini);
    int ans=0,rem=0,temp=0;
    f(i,1,n-1) 
    {
        int x = (v[i-1] * v[i-1]) % m;
        if(vis[x]) 
        {
            rem = n-i;
            temp = x;
            break;
        }
        vis[x] = x;
        ans += x;
        v.pb(x);
    }  
    ans=ans+ini;
    if(rem) {
        while(v.front() != temp) v.pop_front();
        int l= sz(v);
        int res = rem%l;
        int tot = rem/l;
        int sum = 0;
        for(auto i : v) sum += i;

        ans += (tot * sum);
        f(i,0,res-1)
        ans += v[i];
    }
    cout<<ans;
}