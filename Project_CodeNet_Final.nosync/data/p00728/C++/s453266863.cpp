#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n ; i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x) // decltypeで型取得、引数があればva_argsのところに入れる
using namespace std;
typedef long long ll; // long longをllでかけるようにした
const int INF = 1e9;

int main(void){
    while(true){
        int n; cin >> n;
        if(n == 0) return 0;
        else{
            vector<int> Score(n);
            REP(i, n) cin >> Score[i];
            int ave = 0;
            whole(sort, Score);
            for(int i = 1; i < n - 1; i++) ave += Score[i];
            ave /= n - 2;
            cout << ave << endl;
        }
    }
}
