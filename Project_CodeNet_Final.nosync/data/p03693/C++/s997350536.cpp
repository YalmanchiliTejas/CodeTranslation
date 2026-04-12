#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPm(i,n) for(int i=(n)-1;i>=0;i--)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
typedef long long ll;
int main(){
    int r,g,b;
    cin >> r >> g >> b;
    if((10*g+b)%4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
