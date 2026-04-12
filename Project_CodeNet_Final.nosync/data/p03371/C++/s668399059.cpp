#include<bits/stdc++.h>
using namespace std;

using ll= long long;
const ll INF=1LL<<60;
const ll MOD=1e9+7;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll res=INF;
    for(int i=0; i<=2*max(X, Y); i+=2){
        ll total;
        int a=X-i/2, b=Y-i/2, c=i;
        if(a < 0) a=0;
        if(b < 0) b=0; 
        total=a*A+b*B+c*C;
        res=min(res, total);
    }
    cout << res << endl;
    return 0;
}