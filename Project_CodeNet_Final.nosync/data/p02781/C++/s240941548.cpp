#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue> //priority_queue 优先队列
#include <map>
#include <set> //multiset  set<int,greater<int>>大到小
#include <vector>// ::iterator it;
#include <stack>
#include <cmath> // auto &Name : STLName  Name.
#include <utility>
#include <sstream>
#include <string>
#define mod 1000000007
#define mod9 998244353
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
typedef long double ld;
const db eps=1e-10;
const int INF = 0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=2e5+8;
inline ll read(){ll s=0,w=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();return s*w;}
using namespace std;

int t=0,n,m=0,k=0;
string s;
int ans=0;

int C(int x,int y){
    int cnt=1;
    for(int i=0;i<y;i++) cnt*=x--;
    for(int i=2;i<=y;i++) cnt/=i;
    return cnt;
}

int p(int x){
    int cnt=1;
    while(x--) cnt*=9;
    return cnt;
}

int main(){
    cin>>s;
    n=s.size()-1;
    scanf("%d",&k);
    int i,j;
    for(i=k-1,j=0;i>=0&&j<=n;i--,j++){
        while(s[j]=='0') j++;
        int cnt=s[j]-'0'-1;
        if(cnt>0){
            if(n-j>=i) ans+=cnt*p(i)*C(n-j,i);
        }
        if(n-j>=i+1) ans+=p(i+1)*C(n-j,i+1);
    }
    for(int i=0;i<=n;i++){
        if(s[i]>'0') t++;
    }
    if(t>=k) m=1;
    printf("%d\n",ans+m);
    return 0;
}
