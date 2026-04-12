#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n,x,m;
    cin>>n>>x>>m;
    map<int,int>mp,rev;
    int pend=0,tmp=x;
    for(;;pend++,(tmp*=tmp)%=m){
        if(mp.find(tmp)!=mp.end())
            break;
        mp[tmp]=pend;
        rev[pend]=tmp;
    }
    int pbeg=mp[tmp];
    int per=pend-pbeg;
    int psum=0;
    for(int i=0;i<per;i++)
        psum+=rev[i+pbeg];
    int sum=0;
    for(int i=0;i<min(n,pbeg);i++)
        sum+=rev[i];
    if(n>=pbeg){
        n-=pbeg;
        sum+=n/per*psum;
        for(int i=0;i<n%per;i++)
            sum+=rev[i+pbeg];
    }
    cout<<sum<<endl;
}
