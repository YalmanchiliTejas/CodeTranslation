#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;
#define LL long long
#define mp make_pair
#define fr first
#define sc second
#define pb push_back
#define lc (x<<1)
#define rc ((x<<1)|1)
const int N=200005;
int a[N];
int main(){
  //  freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    int i,n,m;
    scanf("%d",&n);m=(n+1)/2;
    for (i=0;i<n;i++){
        int x,id;
        scanf("%d",&x);
        if (!i) id=m;
         else if ((i%2)^(n%2)) id=m+(i+1)/2;
          else id=m-(i+1)/2;
        a[id]=x;
    }
    for (i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
    printf("%d",a[1]);
    for (i=2;i<=n;i++) printf(" %d",a[i]);
    puts("");
  //  system("pause");
    return 0;
}
