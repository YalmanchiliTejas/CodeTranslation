#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int (i)=0;(i) < (N); (i)++)
#define all(V) V.begin(), V.end()
using i64 = int_fast64_t;
using P = pair<i64,i64>;



int main(){
    vector<int> e(12);
    rep(i,12) cin >> e[i];

    sort(all(e));
    bool ok = true;
    
    auto check = [&](int a, int b){
        for(int i=a;i<b;i++) {
            if(e[i] != e[a]) return false;
        }
        return true;
    };

    ok &= check(0,4);
    ok &= check(4, 8);
    ok &=  check(8, 12);

    if(ok) cout << "yes" << endl;
    else cout << "no" << endl;
}

