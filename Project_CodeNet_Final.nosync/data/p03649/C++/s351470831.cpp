#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    vector<ll> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<ll>());
    
    ll K = 0;
    while(true){
        bool change = false;
        for(int i=0;i<N;i++){
            if(a[i] + K >= N){
                change = true;
                ll b = a[i] + K;
                ll k = b / N;
                a[i] -= k * (N + 1);
                K += k;
            }
        }
        if(!change){
            break;
        }
    }
    cout << K << endl;

    return 0;
}