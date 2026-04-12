#include <bits/stdc++.h>
#define  rep(i,n) for(li i = 0; i < (n); ++i)
#define  red(i,n) for(li i = (n)-1; i >= 0; --i)
#define  all(a)   begin(a),end(a)
#define  pb(a)    push_back(a) 
using namespace std;
using li = long long;
using ul = unsigned long long;
using vi = vector<li>;
using vs = vector<string>;
inline ul gcd(ul a,ul b) { return b?gcd(b,a%b):a; }
const int INF=1000000009;


int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    x-=z+z;
    cout<<x/(y+z)+(x%(y+z)>=y)<<endl;

    return 0;
}
