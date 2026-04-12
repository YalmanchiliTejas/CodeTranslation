
/*{{{*/
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>

using namespace             std;
typedef long long           ll;
typedef unsigned long long  ull;
typedef pair<ll, ll>        P;
const double                PIE = 3.141592;

#define rep_n(i, a, b)  for (int i=a; i<b; i++)
#define rep(i, n)       rep_n(i, 0, n)
#define all(v)          (v).begin(), (v).end()
#define item(v)         sizeof(v)/sizeof(v[0])
#define tov(v)          v, v+item(v)
#define mp(x, y)        make_pair(x, y)
#define mset(x, y)      memset(x, y, sizeof(x))
#define chmin(x,y)      (x=min(x, y))
#define chmax(x,y)      (x=max(x, y))
#define SORTI(v)        sort(v, v+item(v))
#define SORT(v)         sort(d.begin(), d.end());
#define UNIQUE(x)       x.erase(unique(all(x)), x.end())
#define ins(x, y, z)    x.insert(x.begin()+y, z)
#define era(x, y)       x.erase(x.begin()+y)
#define era1(x, y, z)   x.erase(x.begin()+y, x.begin()+z)
#define COUNT(x, y)     count(all(x), y)
#define FIND(x, y)      find(all(x), y) - x.begin()

#define ci1(a)          cin>>a 
#define ci2(a, b)       cin>>a>>b
#define ci3(a, b, c)    cin>>a>>b>>c
#define ci4(a, b, c, d) cin>>a>>b>>c>>d
#define co1(a)          cout<<a<<endl;
#define co2(a, b)       cout<<a<<" "<<b<<endl;
#define co3(a, b, c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define co4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
/*}}}*/

int x, y, z, ans;
vector<ll> v;

int main() {
    ci3(x, y, z);
    ans = (x-z)/(y+z);
    co1(ans);

}

///*debug*/co1();
