#include "bits/stdc++.h"
using namespace std;

int main(){
    int N;
    cin >> N;
    int H[N];
    for(int i=0;i<N;i++) cin >> H[i];
    int ans =0;
    int M =0;
    for(int i=0;i<N;i++){
        if(H[i]>=M) ans++;
        M = max(M,H[i]);
    }
    cout << ans << endl;
}