#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#define  ms(a,b) memset(a,b,sizeof(a))

using namespace std;
typedef long long LL;
const LL INF=1e17L;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const int Mod=1e9+7;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if((a*100+b*10+c)%4==0)
        cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    return 0;
}
