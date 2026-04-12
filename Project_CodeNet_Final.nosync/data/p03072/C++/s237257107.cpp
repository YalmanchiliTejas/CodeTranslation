#include <bits/stdc++.h>

#define rep(i,n) for(int i = 0;i < n; i++)

using namespace std;

int main() {
    int n;
    int h[20];
    cin >> n;
    rep(i, n){
        cin >> h[i];
    }
    int max = 0, cnt = 0;
    rep(i, n){
        if(h[i] >= max){
            cnt++;
            max = h[i];
        }
    }
    cout << cnt << endl;
}
