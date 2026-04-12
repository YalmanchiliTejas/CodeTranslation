#include<bits/stdc++.h>
using namespace std;
typedef int _int;
const int N=55;
#define int unsigned long long 
int a[N],ans[N];
int getans(int x,int val){
    if(!val)return 0;
    if(val==1)return x==0;--val;
    int Ans=0;
    if(val>a[x-1])Ans+=ans[x-1],val-=a[x-1];
    else return getans(x-1,val);
    --val,++Ans;
    if(!val)return Ans;
    else if(val<=a[x-1])return Ans+getans(x-1,val);
    else Ans+=ans[x-1];
    return Ans;
}
_int main(){
    ios::sync_with_stdio(false);
    int n,x;cin>>n>>x;
    a[0]=1;ans[0]=1;
    for(int i=1;i<=n;++i)
        a[i]=a[i-1]*2+3,ans[i]=ans[i-1]*2+1;
    cout<<getans(n,x)<<endl;
    return 0;
}
