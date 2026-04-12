#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
using namespace std;
typedef long long LL;
#define ms(a,b) memset(a,b,sizeof(a))
#define eps 1e-8
const int maxn=1e5+100;

LL a[maxn],w[maxn];
int main()
{
    //freopen("c:\\in.txt","r",stdin);
    int x,y,z;
    cin>>x>>y>>z;
    cout<<(x-z)/(y+z)<<endl;
    return 0;
}
