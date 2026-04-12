#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repc(i, b, e) for(auto i = (b); i != (e); i++)

int main(){
    int n, h, s = 0, max = 0;
    cin >> n;
    rep(i, n){
        cin >> h;
        if (max <= h){
            s++;
            max = h;
        }
    }
    cout << s << endl;
    return 0;
}