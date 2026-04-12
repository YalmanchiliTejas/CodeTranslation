#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define REPR(i,n) for(int (i)=(n-1);(i)>=0;i--)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);i++)
#define FORR(i,m,n) for(int (i)=(m-1);(i)>=(n);i--)
#define PRINT(x) {cout<<(x)<<"\n";}

int main(){
    string s = "753";
    char x;
    cin >> x;
    if (s.find(x) != string::npos) PRINT("YES")
    else PRINT("NO")
}