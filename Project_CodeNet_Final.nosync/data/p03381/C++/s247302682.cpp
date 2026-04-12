#define loop(i, s, e) for(ll i = s;i < e;i++)

#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <map>
#include <cmath>
//#include "vector2d.cpp"

using namespace std;
//using namespace libcgl;
typedef long long signed ll;

ll n,x[200000],xx[200000];

int main() {
    cin >> n;
    loop(i,0,n) {cin >> x[i];xx[i]=x[i];}
    sort(xx,xx+n);
    ll m = n / 2 - 1;
    loop(i,0,n) {
        if(x[i] <= xx[m]) cout << xx[m+1] << endl;
        else cout << xx[m] << endl;
    }
}

