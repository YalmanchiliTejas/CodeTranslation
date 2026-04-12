/*Lower_Rating*/
/*Ex*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
using namespace std;

#define LL long long
#define DB double
#define MOD 1000000007
#define Pr pair<int,int>
#define X first
#define Y second
#define MAXN 200
#define eps 1e-10
#define INF 1000000000
#define mem(x,p) memset(x,p,sizeof(x))

LL read(){
  LL x=0,F=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
  return x*F;
}
int add(int a,int b){return (a+b>=MOD)?a+b-MOD:a+b;}
int dec(int a,int b){return (a-b<0)?a-b+MOD:a-b;}
int mul(LL a,int b){return a*b%MOD;}
int fst_pow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=mul(res,a);
        a=mul(a,a);
        b>>=1;
    }return res;
}

int n,a[MAXN+5];

Pr solve(int l,int r,int c){
    if(l>r)return Pr(1,0);
    int mh=INF;
    for(int i=l;i<=r;i++)mh=min(mh,a[i]);
    vector<int> pos;
    pos.push_back(l-1);
    for(int i=l;i<=r;i++)
    if(a[i]==mh)pos.push_back(i);
    pos.push_back(r+1);
    int w=pos.size()-2;
    Pr tmp,v;tmp=Pr(1,1);
    for(int i=0;i<pos.size()-1;i++){
        v=solve(pos[i]+1,pos[i+1]-1,mh);
        tmp.X=mul(tmp.X,v.X);
        tmp.Y=mul(tmp.Y,add(v.X,v.Y));
    }
    return Pr(mul(tmp.X,fst_pow(2,mh-c)),add(mul(tmp.X,dec(fst_pow(2,mh-c),2)),mul(tmp.Y,fst_pow(2,w))));
}

int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    printf("%d",solve(1,n,0).Y);
}
