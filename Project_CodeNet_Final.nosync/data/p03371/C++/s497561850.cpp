#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll A, B, C, X, Y;
    cin>>A>>B>>C>>X>>Y;
    ll Minim=A*X+B*Y+C*X*2+C*Y*2;
    rep(Cn, max(X, Y)*2+1){
        ll An=max(X-Cn/2, (ll)0);
        ll Bn=max(Y-Cn/2, (ll)0);
        ll cost=An*A+Bn*B+Cn*C;
        //cout<<cost<<sp<<An<<sp<<Bn<<sp<<Cn<<endl;
        Minim=min(Minim, cost);
    }
    cout<<Minim<<endl;
    return 0;
}
