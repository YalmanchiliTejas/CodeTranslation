#include <bits/stdc++.h>
#define ls k<<1,l,mid
#define rs k<<1|1,mid+1,r
#define mp(x,y) make_pair(x,y)
#define r(x) read(x)
#define rrr(x,y,z) read(x);read(y);read(z)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
typedef long long LL;
typedef pair<int,int> pt;
const int N=2e5+5;
const int M=2e3+5;
const int INF=0x7fffffff;
const int mod=1e9+7;
const double eps=1e-8;
const double pi=acos(-1);
LL n,m;
char s[N];
template<class T>
inline void read(T &x)
{
    char c; x=1;
    while((c=getchar())<'0'||c>'9') if(c=='-') x=-1;
    T res=c-'0';
    while((c=getchar())>='0'&&c<='9') res=res*10+c-'0';
    x*=res;
}
int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    r(m);
    LL ans=0;
    FOR(i,1,len-1){
        if(m==1){
            ans+=9;
        }
        else if(m==2){
            if(i>=2) ans+=81*(i-1);
        }
        else if(m==3){
            if(i>=3) ans+=81ll*9*(i-1)*(i-2)/2;
        }
    }

    if(m==1) ans+=s[1]-'0';
    else if(m==2){
        int get=s[1]-'0'-1;
        if(get>0) ans+=get*9*(len-1);
        FOR(i,2,len){
            bool flag=1;
            FOR(j,2,i-1) if(s[j]!='0') flag=0;
            if(flag){
                ans+=s[i]-'0';
            }
            else ans+=9;
        }
    }
    else if(m==3){
        int get=s[1]-'0'-1;
        if(get>0) ans+=get*9*9*(len-1)*(len-2)/2;
        FOR(i,2,len){
            bool flag=1;
            FOR(j,2,i-1) if(s[j]!='0') flag=0;
            if(flag){
                int gg=s[i]-'0'-1;
                if(gg>0) ans+=gg*9*(len-i);
                if(gg>=0){
                    FOR(j,i+1,len){
                        bool ff=1;
                        FOR(k,i+1,j-1) if(s[k]!='0') ff=0;
                        if(ff){
                            ans+=s[j]-'0';
                        }
                        else ans+=9;
                    }
                }
            }
            else{
                ans+=9*9*(len-i);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}