#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N; cin >> N;
    vector<int> H(N);
    for(int i = 0 ; i < N; i++) cin >> H[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        bool flg = true;
        for(int j = 0; j < i; j++){
            if(H[j] > H[i]){
                flg = false;
                break;
            }
        }
        if(flg) ans++;
    }
    cout << ans << endl;
}