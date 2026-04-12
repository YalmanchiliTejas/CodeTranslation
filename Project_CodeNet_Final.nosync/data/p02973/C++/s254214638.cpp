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
    multiset<int> s;
    rep(i,N){
        auto d = s.lower_bound(A[i]);
        if(d == s.begin()){
            s.insert(A[i]);
        }
        else{
            d--;
            s.erase(d);
            s.insert(A[i]);
        }
    }
    cout << s.size() << endl;
}
