//2019.4.13 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
#define RG register
inline int read(){
    res s=0,ch=getchar();
    bool w=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline LL Read(){
    RG LL s=0;
    res ch=getchar();
    bool w=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void swap(res &x,res &y){
    x^=y^=x^=y;
}
namespace MAIN{
    int n;
    int a[20+10];
    int ans=1;
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)a[i]=read();
        res now=a[1];
        for(res i=2;i<=n;i++){
            if(now>a[i])continue;
            ans++,now=a[i];
        }
        printf("%d\n",ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}