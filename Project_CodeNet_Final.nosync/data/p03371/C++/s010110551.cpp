#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll sum = 0,mini = INF;
    mini = min(A+B,C*2);
    sum += min(X,Y) * mini;
    mini = min(C*2,X > Y ? A : B);
    sum += (max(X,Y)-min(X,Y)) * mini;

    cout << sum << endl;
}