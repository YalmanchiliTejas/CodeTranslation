#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <cmath>
#include <cassert>
#include <cstdio>

// #include <unordered_set>
// #include <unordered_map>

#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())

#define pb push_back
#define mp make_pair

int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int lcm(int a,int b){int c=gcd(a,b);a/=c;return a*b;}

typedef std::pair<int, int> P;
typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;
const int INF = 1e9;
const ll LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const double EPS = 1e-10;
const double PI  = acos(-1.0);

using namespace std;

// #define int long long

signed main(){
  

    ios::sync_with_stdio(false);
    cin.tie(0);
    //cin高速化

    int ans=INF;

    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    int x_count=-1;
    int y_count=-1;

    for(int i=0;i<=200000;i+=2){

        int tmp=0;

        x_count++;
        y_count++;

        // cout<<x_count<<" "<<y_count<<endl;

        int tmp_a=max(x-x_count,0);
        int tmp_b=max(y-y_count,0);





        // cout<<i<<" "<<x_count<<" "<<y_count<<" "<<tmp_a<<" "<<tmp_b<<endl;

        tmp=i*c+tmp_a*a+tmp_b*b;
        ans=min(ans,tmp);
        // cout<<ans<<endl;

    }

    cout<<ans<<endl;

    return 0;

}

// 97501500
// 100000000
// 103749000