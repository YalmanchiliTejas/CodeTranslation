#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    deque<int> d;
    rep(i,N){
        int p = lower_bound(d.begin(),d.end(),A[i])-d.begin();
        if(p == 0){
            d.push_front(A[i]);
        }
        else{
            d[p-1] = A[i];
        }
    }
    int ans = d.size();
    cout << ans << endl;
}
