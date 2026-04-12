#include<iostream>
#include<cstring>

using namespace std;

typedef long long LL;

const int N=2e5+10;
const int mod=1e9+7;

int n;
int a[N];
int s[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    s[0]=0;
    for(int i=1;i<=n;++i){
        LL tmp=(LL)s[i-1]+a[i];
        tmp%=mod;
        s[i]=tmp;
    }
    LL res=0;
    for(int i=1;i<n;++i){
        LL k=(s[n]-s[i]);
        if(k<0) k+=mod;
        LL tmp=(LL)a[i]*k;
        tmp%=mod;
        res+=tmp;
        res%=mod;
    }
    cout<<res<<endl;
    return 0;
}