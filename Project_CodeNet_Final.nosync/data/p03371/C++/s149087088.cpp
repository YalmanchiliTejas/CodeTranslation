#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(long long)>
using namespace std;
#define All(v) (v).begin(),(v).end()
const long long mod = 1000000007;
const long long inf = mod*mod;
const long long MAXS = 114514;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
signed main(){
    long long a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    long long res = 0;
    if(x>=y){
        res+=min(2*c,b+a)*y;
        x-=y;
        res+=min(2*c,a)*x;
    }
    else{
        res+=min(2*c,a+b)*x;
        y-=x;
        res+=min(2*c,b)*y;
    }
    cout<<res<<endl;
}