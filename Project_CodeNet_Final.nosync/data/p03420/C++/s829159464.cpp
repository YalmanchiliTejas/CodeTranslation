#include<bits/stdc++.h>
#define MAXN 1100000
using namespace std;

inline void read(long long &x){
    char ch;
    bool flag=false;
    for (ch=getchar();!isdigit(ch);ch=getchar())if (ch=='-') flag=true;
    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
    x=flag?-x:x;
}

inline void read(int &x){
    char ch;
    bool flag=false;
    for (ch=getchar();!isdigit(ch);ch=getchar())if (ch=='-') flag=true;
    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
    x=flag?-x:x;
}


inline void write(long long x){
    static const long long maxlen=100;
    static char s[maxlen];
    if (x<0) {   putchar('-'); x=-x;}
    if(!x){ putchar('0'); return; }
    long long len=0; for(;x;x/=10) s[len++]=x % 10+'0';
    for(long long i=len-1;i>=0;--i) putchar(s[i]);
}


long long n , m;

int main(){
    read(n);    read(m);
    if ( m==0 )
        {
            cout<<1ll*n*n<<endl;
            return 0;
        }
    long long ans=0;
    for (int i=m+1;i<=n;i++)
    {
        ans+=n/i*(i-m)+max( n%i-m+1 ,  0ll );
        //cout<<n/i*(i-m)+max( n%i-m+1 ,  0ll )<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
