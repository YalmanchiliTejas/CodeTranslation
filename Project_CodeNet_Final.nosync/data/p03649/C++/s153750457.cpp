#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <list>
#include <bitset>

using namespace std;

#define CVector CPoint
typedef long long LL;
typedef unsigned long long ULL;

const LL mod=1e9+7;
const double PI=acos(-1);
const double EPS=1e-6;
const int INF=0x3f3f3f3f;
inline int readint(){int sum=0;char c=getchar();bool f=0;while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}while(c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}if(f) return -sum;return sum;}
inline LL readLL(){LL sum=0;char c=getchar();bool f=0;while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}while(c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}if(f) return -sum;return sum;}

int n;
LL a[55];

int main(){//ios_base::sync_with_stdio(0);cin.tie(0);
    n=readint();
    for(int i=1;i<=n;i++) a[i]=readLL();
    LL ans=0;
    while(1){
        bool fg=true;
        for(int i=1;i<=n;i++){
            if(a[i]>n-1){
                fg=false;
                break;
            }
        }
        if(fg) break;
        LL ct=0;
        for(int i=1;i<=n;i++){
            LL s=a[i]/n;
            ct+=s;
            a[i]-=s*(n+1);
        }
        for(int i=1;i<=n;i++){
            a[i]+=ct;
        }
        ans+=ct;
    }
    printf("%lld\n",ans);
    return 0;
}

//cout.setf(ios::fixed);
//cout<<fixed<<setprecision(10)<<s<<endl;
