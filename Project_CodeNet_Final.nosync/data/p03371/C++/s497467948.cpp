#include<bits/stdc++.h>

using namespace std;

#define max(a,b) (a>b? a:b)
#define min(a,b) (a<b? a:b)
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}

#pragma GCC Optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment (linker,"/stack:200000000")

typedef long long ll;

bool Finish_read;

template<class T>inline void read(T &x){Finish_read=0;x=0;T f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}

unsigned CostA,CostB,CostC,sum=0;
int X,Y;

int main() {
    read(CostA),read(CostB),read(CostC),read(X),read(Y);
    CostC <<= 1;
    while(X>0||Y>0) {
        if(CostC<CostA+CostB&&X>0&&Y>0)
            --X,--Y,sum+=CostC;
        else if(X>0&&CostA>CostC)
            --X,sum+=CostC;
        else if(Y>0&&CostB>CostC)
            --Y,sum+=CostC;
        else if(X>0)
            --X,sum+=CostA;
        else if(Y>0)
            --Y,sum+=CostB;
    }
    writeln(sum);
    return 0;
}
