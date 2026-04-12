// copied
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
typedef long long ll;
ll ans,a[60];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    ll* p;
    while(*(p=max_element(a+1,a+n+1)) >= (ll)n){
        for(int i=1;i<=n;++i){
            if(a+i!=p){
                a[i]+=(*p)/(ll)n;
            }
        }
        ans+=(*p)/(ll)n;
        (*p)%=(ll)n;
    }
    cout<<ans<<endl;
    return 0;
}
