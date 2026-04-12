#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int res = a*x+b*y;

    int z = 0;
    while((x>=1) or(y>=1)){
        z++;
        if(x>0) x--;
        if(y>0) y--;

        res = min(a*x+b*y+2*c*z,res);
    }

    cout << res << endl;

}