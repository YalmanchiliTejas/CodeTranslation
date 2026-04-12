#include "bits/stdc++.h"

using namespace std;

int main() {
    int N,H,M;
    cin >> N;
    int j = 0;
    M = 0;
    int ans = 0;
    while(j < N){
        cin >> H;
        j++;
        if(M <= H){
            ans = ans + 1;
            M = H;
        }
    }
    cout << ans << endl;
}