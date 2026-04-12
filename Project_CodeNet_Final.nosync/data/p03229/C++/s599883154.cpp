#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define eps 1e-8
#define pb push_back
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define clr(a,b) memset(a,b,sizeof(a)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N=1e5+10;
typedef long long ll;
typedef unsigned long long ull;
ll a[N];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int l=1,r=n;
    ll ans1=0,ans2=0;
    for(int i=1;i<n-1;i++){
        ans1+=abs(a[r]-a[l]);
        if(i%2) r--;
        else l++;
    }
    l=1;r=n;
    for(int i=1;i<n-1;i++){
        ans2+=abs(a[r]-a[l]);
        if(i%2) l++;
        else r--;
    }
    if(n%2){
        int id=n/2+1;
        ans1=ans1+max(abs(a[n]-a[id]),abs(a[id-1]-a[id]));
        ans2=ans2+max(abs(a[1]-a[id]),abs(a[id+1]-a[id]));
    }
    else{
        int id=n/2;
        ans1=ans1+max(abs(a[n]-a[id]),abs(a[id+1]-a[id]));
        id++;
        ans2=ans2+max(abs(a[1]-a[id]),abs(a[id-1]-a[id]));
    }
    printf("%lld\n",max(ans1,ans2));
    return 0;
}
