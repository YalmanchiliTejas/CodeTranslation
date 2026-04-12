#include<bits/stdc++.h>
using namespace std;using int32=int_fast32_t;using uint32=uint_fast32_t;using int64=int_fast64_t;using uint64=uint_fast64_t;using pi=pair<int32,int32>;using pll=pair<int64,int64>;using vi=vector<int32>;using vvi=vector<vector<int32>>;using vll=vector<int64>;using ll=int64;using ull=uint64;
#define all(x) x.begin(),x.end()
inline ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
ll a[51], p[51];
inline ll f(const ll& N, const ll& X){
    if(N==0) return X<=0?0:1;
    else if(X<=a[N-1]+1) return f(N-1,X-1);
    else return p[N-1]+1+f(N-1,X-a[N-1]-2);
}
void Main(){
    ll N = read(),X = read();
    a[0] = 1;
    p[0] = 1;
    for(int i=0;i<N;i++){
        a[i+1] = a[i]*2+3;
        p[i+1] = p[i]*2+1;
    }
    printf("%lld\n", f(N,X));
}
int main(){cin.tie(nullptr);ios::sync_with_stdio(false);Main();return 0;}
