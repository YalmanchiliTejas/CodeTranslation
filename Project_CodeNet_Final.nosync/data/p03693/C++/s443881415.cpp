#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1000000000 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    cout << (((100*r+10*g+b)%4==0)?"YES":"NO") <<endl;
    return 0;
}