// by betrue12
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

vector<ll> len(51);
vector<ll> patti(51);

ll rec(int n, ll x){
    ll ans = 0;

    if (x == len[n]) return patti[n];
    
    // 最初のバンズをカウント
    x--;

    // 最初の l - 1 バーガーの部分のパティをカウント
    if (x > 0){
        ll l = min(x, len[n - 1]);
        ans += rec(n - 1, l);
        x -= l;
    }

    // 真ん中のパティをカウント
    if (x > 0){
        ans++;
        x--;
    }

    // 二番目の l - 1 バーガーの部分のパティをカウント
    if (x > 0){
        ll l = min(x, len[n - 1]);
        ans += rec(n - 1, l);
        x -= l;
    }

    return ans;
}

int main(){
    int n;
    ll x;
    cin >> n >> x;

    len[0] = 1;
    patti[0] = 1;

    for (int i = 1; i <= n; i++){
        len[i] = 2 * len[i - 1] + 3;
        patti[i] = 2 * patti[i - 1] + 1;
    }

    cout << rec(n, x) << endl;

    return 0;
}