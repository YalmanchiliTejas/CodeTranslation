#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    vector<ll> H(30);
    for(int i = 0; i < N; i++) cin >> H[i];

    ll num = 1;
    for(int i = 1; i < N; i++){
        bool flag = true;
        for(int j = 0; j < i; j++){
            if(H[j] > H[i]) flag = false;
        }
        if(flag) num++;
    }
    cout << num << endl;
}