#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,X,Y,m,l,s, res=1e9;

    cin >> A >> B >> C >> X >> Y;

    m = A*X + B*Y;
    res = min(m,res);
    l = max(X,Y);
    s = min(X,Y);
    for (int i=0;i<s;i++){
        m = m + 2*C - A - B;
        res = min(m,res);
    }
    if (X >= Y){
        res = min (res,m+(2*C-A)*(l-s));
    }
    else{
        res = min (res,m+(2*C-B)*(l-s));
    }
    //sort(v.rbegin(), v.rend(), [](auto& x, auto& y){return x[1] < y[1];});

    cout << res << endl;
}
