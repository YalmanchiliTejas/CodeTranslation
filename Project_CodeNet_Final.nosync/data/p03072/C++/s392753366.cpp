#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    int n;
    cin >> n;
    int h[n];
    rep(i,n) cin >> h[i];
    int ans = 1;
    for(int i=1;i<n;i++){
        int k = 0;
        for(int j=0;j<i;j++){
            if(h[j] <= h[i]){
                k++;
            }
        }
        if(k == i && h[i-1] <= h[i]){
            ans++;
        }
    }
    cout << ans << endl;
}