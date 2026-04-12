#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 2147483647//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string s;
    cin >> s;
    if(s[0] == 'A' && (s[1] == 'B' || s[2] == 'B')){
        cout << "Yes" << endl;
        return 0;
    }else if(s[1] == 'A' && (s[0] == 'B' || s[2] == 'B')){
        cout << "Yes" << endl;
        return 0;
    }else if(s[2] == 'A' && (s[0] == 'B' || s[1] == 'B')){
        cout << "Yes" << endl;
        return 0;        
    }
    cout << "No" << endl;
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