//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)




int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    rep1(i, n){
        cin >> a[i];
    }
    long long ans = 0;
    long long waru = pow(10, 9) + 7;
    long long tem = 0;
    rep1(i, n){
        tem += a[i];
        tem = tem % waru;
    }
    rep1(i, n){
        tem -= a[i];
        if(tem < 0){
            tem += waru;
        }
        ans += tem * a[i];
        ans = ans % waru;
    }

    cout << ans;
    
}
