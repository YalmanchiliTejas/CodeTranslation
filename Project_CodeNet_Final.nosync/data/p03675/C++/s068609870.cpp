#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define CVector CPoint
#define INF 0x3f3f3f3f
#define MAXN 1e5
const LL mod=1e9+7;
const double PI=acos(-1.0);
const double EPS=1e-10;
inline int readint(){int sum=0;char c=getchar();bool f=0;while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}if(f) return -sum;return sum;}
inline LL readLL(){LL sum=0;char c=getchar();bool f=0;while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}while(c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}if(f) return -sum;return sum;}

int a[200005],b[200005];
int main(){ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int p=1,q=n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int j=n;
    while(j>=1){
        b[p++]=a[j];
        j-=2;
    }
    if(n%2) j=2;
    else j=1;
    while(j<=n){
        b[p++]=a[j];
        j+=2;
    }
    for(int i=1;i<=n;i++){
        cout<<b[i];
        if(i<n) cout<<" ";
        else cout<<endl;
    }
    return 0;
}

//cout.setf(ios::fixed);
//cout<<fixed<<setprecision(10)<<s<<endl;
