/**
 *  author:   TakeruOkuyama
 *  created:  2020-04-15 11:17:28
**/
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
const int INF = 999999999;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    int max = 0;
    rep(i, N){
        cin >> H[i];
    }
    int ans = 0;
    rep(i, N){
        if(max <= H[i]){
            ans++;
            max = H[i];
        }
    }
    cout << ans << endl;
return 0;}

/**
 * g++ code.cpp
 * ./a.out
 * shift + ctrl + i
**/ 