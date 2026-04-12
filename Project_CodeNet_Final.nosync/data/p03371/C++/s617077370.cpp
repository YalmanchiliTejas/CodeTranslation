#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    vector<int> piza = {a,b};
    vector<int> count = {x,y};
    int ans = 0;
    if(c*2 > a+b){
        ans = a*x + b*y;
    }
    else{
        ans += min(x,y) * c * 2;
        int z,zz;
        if(x >= y){
            z = 0;
            zz = 1;
        }
        else{
            z = 1;
            zz = 0;
        }
        ans += min(piza.at(z)*(count.at(z)-count.at(zz)) , c*2*(count.at(z)-count.at(zz)));
    }
    cout << ans << endl;
}