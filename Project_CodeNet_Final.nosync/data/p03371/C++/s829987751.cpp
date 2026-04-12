#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
    ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    ll p,q,r;
    p=a*x+b*y;
    q=c*max(x,y)*2;
    if(x>y){
        r=c*y*2+a*(x-y);
    }else{
        r=c*x*2+b*(y-x);
    }
    cout<<min(p,min(q,r));
    
    return 0;
}
