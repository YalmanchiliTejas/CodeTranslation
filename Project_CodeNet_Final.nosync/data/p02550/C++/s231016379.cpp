#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
 
 
 
int main() 
{
    ll n, x, m;
    cin >> n >> x >> m;
    vector<int> id(m, -1);
   
    vector<int> a;
   
    int len = 0;
    ll tot = 0;
   
    while (id[x] == -1) 
	{
        a.push_back(x);
        id[x] = len;
        len++;  //total len till next cycle
       
	    tot = tot + x;
        x = (x*x)%m;
    }
 
    int c = len-id[x];  //cycle len
    ll s = 0;
    for (int i = id[x]; i < len; i++) s += a[i];  //cycle sum
 
    ll ans = 0;
  
  
    if (n <= len) 
	{
        rep(i,n) ans += a[i];
    }
    else 
	{
        
		ans =  ans+ tot;
        n = n- len;
        ans = ans+ s*(n/c);
        n = n% c;
       
	   
	    rep(i,n) ans += a[id[x]+i];
    }
    cout << ans << endl;
  
}