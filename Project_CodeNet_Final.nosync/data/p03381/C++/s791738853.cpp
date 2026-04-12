#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;
struct pos{
    int val;
    int th;
};
int n;
pos a[MAXN];
int map[MAXN];
bool cmp(pos a,pos b){
    if(a.val<b.val)
        return true;
    else return false;
}
int main(){
    cin>>n;
    for(int i=1; i<=n ;i++){
        scanf("%d",&a[i].val);
        a[i].th=i;
    }
    sort(a+1,a+n+1,cmp);

    for(int i=1; i<=n; i++){
        map[a[i].th] = i;
    }

    for(int i=1; i<=n; i++){
        if(map[i]<=n/2){
            printf("%d\n",a[n/2+1].val);
        }
        else
            printf("%d\n",a[n/2].val);
    }
    return 0;
}