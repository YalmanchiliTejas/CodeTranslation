#include <iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
#define LL long long
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define sz(v) ((int)sizeof(v))
#define N 100005

int main()
{
    int a,b;
    double ans,tmp;
    cin>>a>>b;
    tmp=1.0/a+1.0/b;
    ans=1.0/tmp;
    printf("%.9f\n",ans);
    return 0;
}
