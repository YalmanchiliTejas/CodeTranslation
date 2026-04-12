#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
using namespace std;

#define rep(i, s) for (int i = 0; i < s; ++i)
#define all(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define VEC(a, n) vector<int>a(n)
#define PQ(a) priority_queue<int>a
#define PQmin(a) priority_queue< int, :vector<int>, greater<int> >a
#define PAIR pair<int, int>
/*
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long  ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int n,k;
    cin>>n>>k;
    //n=7,k=1だとすると、例えばb=3で固定すると、a=0~nまで動かすとあまりは0,1,2,0,1,2,0,1となる。
    //つまり、あるbにおいて、求める数は、(n/b)*(b-k)+n%b-k+1個をbについて足せば良い。
    //最後にa=0の場合を引けば良い。
    ll ans=0;
    for(int b=1;b<=n;b++){
        ans+=(n/b)*max((b-k),0)+max(n%b-k+1,0);
        // cout<<ans<<endl;
    }
    if(k==0){
        ans-=n;
    }
    cout<<ans<<endl;





    return 0;
}
