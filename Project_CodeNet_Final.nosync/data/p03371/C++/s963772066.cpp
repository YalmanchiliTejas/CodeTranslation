#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int mini = INF;

    for(int i = 0; i <= 100000; i++){
        int price = 0;
        int ap = (X - i) * A;
        if(ap < 0) ap = 0;
        int bp = (Y - i) * B;
        if(bp < 0) bp = 0;
        int abp = (i * 2) * C;
        price = ap + bp + abp;
        mini = min(mini, price);
    }

    cout << mini << endl;
    return 0;
}
