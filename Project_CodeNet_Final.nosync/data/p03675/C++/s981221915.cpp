#include<bits/stdc++.h>
/*
g++ -std=c++11 -Wall -g -fsanitize=undefined -D_GLIBCXX_DEBUG arc/arc077/c.cpp
*/
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define INF (1e16)
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);//おまじないでcin, cout早くする
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    if(n % 2 == 0){
        for(int i = n; i >= 2; i--){
            if(i % 2 == 1) continue;
            else cout << a[i] << " ";
        }
        for(int i = 1; i <= n; i++){
            if(i % 2 == 0) continue;
            else cout << a[i] << " ";
        }
    }

    if(n % 2 == 1){
        for(int i = n; i >= 1; i--){
            if(i % 2 == 0) continue;
            else cout << a[i] << " ";
        }
        for(int i = 2; i <= n; i++){
            if(i % 2 == 1) continue;
            else cout << a[i] << " ";
        }
    }

    cout << "\n";
    return 0;
}