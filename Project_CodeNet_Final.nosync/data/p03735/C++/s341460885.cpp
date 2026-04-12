#include<iostream>
#include<set>
#include <bitset>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include<string>
#include<string.h>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
#include <limits>
#include <numeric>
#include <type_traits>
#include<bitset>
#define int long long
#define ll long long
#define mod  1000000007
#define inf 1e17
#define rep(i,j,n) for(int i=j;i<n;i++)
#define P pair<int,int>
double pi = 3.141592653589793;
using namespace std;
//ここから始めよう
struct node{int x,y;}a[214514];
multiset<int> S1,S2;
bool cmp(node x,node y){return x.x<y.x;}
int ans=0;
signed main(){
    int n;
    cin>>n;
    if (n==1)  {puts("0");  return 0;}
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].x>>a[i].y;
        if (a[i].x>a[i].y)  swap(a[i].x,a[i].y);
        S1.insert(a[i].x),S2.insert(a[i].y);
    }
    ans=1LL*(*S1.rbegin()-*S1.begin())*(*S2.rbegin()-*S2.begin());
    sort(a+1,a+n+1,cmp);
    for (int i=1; i<=n; i++)
    {
        S1.erase(S1.find(a[i].x)),S1.insert(a[i].y);
        S2.erase(S2.find(a[i].y)),S2.insert(a[i].x);
        ans=min(ans,1LL*(*S1.rbegin()-*S1.begin())*(*S2.rbegin()-*S2.begin()));
    }
    cout<<ans<<endl;
    return 0;
}
