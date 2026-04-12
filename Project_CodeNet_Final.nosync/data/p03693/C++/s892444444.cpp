#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c;
    d = a*100 + b*10 + c;
    if(d%4 == 0) puts("YES");
    else puts("NO");
    return 0;
}