#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define P2 pair<LL,int>
#define ls(i) seg[i].lc
#define rs(i) seg[i].rc
using namespace std;
const int N = 18;
const int mod = 1e9 + 7;

int main()
{

    int a , b , c;
    cin>>a>>b>>c;
    int ans = a * 100 + b* 10 +c;
    if(ans % 4 == 0) puts("YES");
    else puts("NO");
    return 0;
}

