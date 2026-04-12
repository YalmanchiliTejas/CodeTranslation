#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
#define INF 1<<30

int main()
{
    int X,Y,Z;
    cin >> X >> Y >> Z;
    int Q = X/(Y+Z);
    int R = X%(Y+Z);
    if(R>=Z)cout << Q << endl;
    else cout << Q-1 << endl;
    return 0;
}