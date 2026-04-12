#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()      //昇順
#define RALL(obj) (obj).rbegin(), (obj).rend()   //降順
#define print(obj) cout << obj << endl
#define scan(obj) cin >> obj

typedef long long ll;

using namespace std;

int main(void){
    int n, count = 1, MAX = 0;
    cin >> n;
    vector<int> h(n);
    rep(i, n){
        cin >> h[i];
    }
    MAX = h[0];
    for(int i = 1; i < n; i++){
        if(MAX <= h[i]){
            count++;
            MAX = h[i];
        }
    }
    print(count);
}