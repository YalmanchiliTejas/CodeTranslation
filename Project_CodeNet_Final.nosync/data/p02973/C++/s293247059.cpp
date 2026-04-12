#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = (ll)1e16;

int main(void){
    int N; 
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<ll> color(N, INF);
    for(int i = N-1; i >= 0; i--){
        *upper_bound(color.begin(), color.end(), A[i]) = A[i];
    }

    cout << lower_bound(color.begin(), color.end(), INF) - color.begin() << '\n';

    return 0;
}