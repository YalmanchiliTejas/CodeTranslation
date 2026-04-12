#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define F first
#define S second
int n;
int ans[200005];
P a[200005];
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].F);
        a[i].S=i;
    }
    sort(a,a+n);
    int x=a[(n-1)/2].F,y=a[n/2].F;
    for(int i=0;i<=(n-1)/2;i++)ans[a[i].S]=y;
    for(int i=n/2;i<n;i++)ans[a[i].S]=x;
    for(int i=0;i<n;i++)printf("%d\n",ans[i]);
}