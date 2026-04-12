#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPm(i,n) for(int i=(n)-1;i>=0;i--)
#define REP1(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;

int main(){
    int X,Y,Z;
    cin >> X >> Y >> Z;
    cout << (X-Z)/(Y+Z) << endl;
    return 0;
}
