#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define MAX 1000001

void _main(){
    vector<ll> out;
    ll a,b,c,x,y; cin >> a>> b>> c>> x>> y;
    c*=2;
    out.push_back(a*x+b*y);
    if(x>y) {
        out.push_back(c*y+a*(x-y));
        out.push_back(c*x);
    }
    else {
        out.push_back(c*x+b*(y-x));
        out.push_back(c*y);
    }
    cout << *min_element(ALL(out)) << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    