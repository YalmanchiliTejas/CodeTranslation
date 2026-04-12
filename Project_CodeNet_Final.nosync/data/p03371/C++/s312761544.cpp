#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    long long a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    if(a+b < 2*c){
        cout << a*x + b*y;
    }else{
        long long cc = min(x,y);
        cout << cc * 2 * c + max(x-cc,(long long)0) * min(a,2*c) + max(y-cc,(long long)0) * min(b,2*c);
    }

    return 0;
}