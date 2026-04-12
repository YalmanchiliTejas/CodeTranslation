#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 200000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
LL a[N];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    LL res=0;
    while(true){
        LL maxx=a[1];
        int pos=1;
        for(int i=2;i<=n;i++){
            if(a[i]>maxx){
                maxx=a[i];
                pos=i;
            }
        }

        if(maxx<=n-1)
            break;

        for(int i=1;i<=n;i++){
            if(i==pos)
                a[i]=maxx%n;
            else
                a[i]+=maxx/n;
        }
        res+=(maxx/n);
    }
    printf("%lld\n",res);
    return 0;
}
