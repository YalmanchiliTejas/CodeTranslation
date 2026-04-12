#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main(){
    int n, m;
    cin >> n;
    m = (int)pow(2, n);
    rep(i, m){
        bitset<20> x(i);
        cout << i << ":";
        rep(j, n){
            if(x.test(j)){
                cout << " " << j;
            }
        }
        cout << endl;
    }
    return 0;
}
