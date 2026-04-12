#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> h(n,0);
    rep(i,n)cin >> h.at(i);
    int max_height = 0;
    int res = 0;
    rep(i,n){
        if(max_height <= h.at(i)){
            res++;
            max_height = h.at(i);
        }
    }
    cout << res << endl;
    return 0;
}

/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/