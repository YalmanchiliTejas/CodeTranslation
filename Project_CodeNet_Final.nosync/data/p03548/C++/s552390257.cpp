#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define mem(a,b) memset(a,b,sizeof(a))
#define shutdown ios::sync_with_stdio(false)
#define MAX 10e18+1000
#define INF 0x3f3f3f3f
#define MAR 10e5+100

int main() {
    shutdown;
    int a,b,c;
    cin>>a>>b>>c;
    a=a-c;
    cout<<a/(b+c)<<endl;
    return 0;
}

