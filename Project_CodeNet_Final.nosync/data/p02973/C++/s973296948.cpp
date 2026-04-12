#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll N; cin >> N;
    vector<ll> A(N); for(int i = 0; i < N; i++) cin >> A[i];
    multiset<ll> ST;
    ST.insert(A[0]);
    for(int i = 1; i < N; i++){
        if(A[i] < *(ST.begin())) ST.insert(A[i]);
        else{
            auto itr = ST.lower_bound(A[i]);
            if(itr == ST.begin()) { ST.insert(A[i]);continue;}
            itr--;
            ST.erase(itr);
            ST.insert(A[i]);
        }
    }
    cout << ST.size() << endl;
}
