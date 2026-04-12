#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int H_max = 0, ans = 0;
    for(int i = 0; i < N; i++){
        int H; cin >> H;
        H_max = max(H_max, H);
        if(H >= H_max) ans++;
    }

    cout << ans << endl;    
}