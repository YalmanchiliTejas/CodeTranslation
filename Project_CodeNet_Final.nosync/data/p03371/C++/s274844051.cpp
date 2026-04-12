#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <functional>
#define inf 1000000000
using namespace std;
typedef long long ll;
const int MAXN=1e9+10;
const int MAX=1e3+10;
const int MOD=1e9+7;
const double eps=1e-6;



int main(){
    #ifdef ONLINE_JUDGE
    #else

    //freopen("output.txt","w",stdout);
    #endif

    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int flag=0;
    if((a+b)<c*2)   flag=-1;
    else    flag=1;
    int temp=min(x,y);
    int ans=0,ans1;
    ans1=min(max(x,y)*2*c,a*x+b*y);
    if(flag==-1)
        ans+=(a+b)*temp;
    else
        ans+=c*2*temp;
    x-=temp;y-=temp;
    ans+=x*a;
    ans+=y*b;
    cout<<min(ans,ans1)<<endl;

    return 0;
}