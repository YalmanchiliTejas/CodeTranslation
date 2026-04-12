#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool check(int n, vector<int> H){
    bool HorL = true;
    rep(i, n){
        if(H[i] > H[n] ){
            HorL = false;
            break;
        }
    }
    return HorL;
}

int main(){
    int N, count;
    cin >> N;
    vector<int> H(N);
    rep(i, N){
        cin >> H[i];
    }

    rep(i, N){
        if(check(i, H) == true){
            count++;
        }
    }
    cout << count << endl;
}