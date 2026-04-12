#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;




int main(){
    ll N; cin >> N;
    vector<ll> A(N); for(int i = 0; i < N; i++) cin >> A[i];
    vector<ll> V;
    for(int i = N-1; i >= 0; i--){
        ll X = A[i];
        auto itr = upper_bound(V.begin(), V.end(), X);
        if(itr == V.end()) {
            V.push_back(X);
        }
        else{
            ll idx = distance(V.begin(), itr);
            V[idx] = X;
        }
    }
    cout << V.size() << endl;
}