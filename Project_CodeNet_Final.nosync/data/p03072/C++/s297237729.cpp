#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    int sum = 1;
    for(int now = 1; now < N; now++){
        bool can = true;
        for(int i = 0; i < now; i++){
            if(H[now] < H[i]) can = false;
        }
        if(can) sum++;
    }
    cout << sum << endl;

}
