#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define IOSF ios::sync_with_stdio(false)
typedef long long LL;
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=10e5+5;
const int MOD=10e9+7;

int a,b,n,flag=1;
LL math[MAX];
LL com[MAX];

int main() {
    IOSF;
    LL temp,mid;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>math[i];
        com[i]=math[i];
    }
    sort(math,math+n+1);
    mid=math[n/2];
    for(int i=1;i<=n;i++){
        temp=com[i];
        if(temp<=mid)
            cout<<math[n/2+1]<<endl;
        else
            cout<<mid<<endl;
    }
    return 0;
}
