#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    ll N;
    cin >> N;
    ll A[N];
    for(ll i = 0; i < N; i++){
        cin >> A[i];
        A[i] *= -1;
    }
    ll DP[N];
    fill(DP,DP + N,1e+9);
    for(int i = 0; i < N; i++){
        *upper_bound(DP,DP + N,A[i]) = A[i];
    }
    ll l = 0;
    for(int i = 0; i < N; i++){
        if(DP[i] == 1e+9){
            break;
        }
        l++;
    }
    cout << l << endl;
}
