#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define F first
#define S second
int n;
P a[200005];
ll xma,xmi=1000000000,yma,ymi=1000000000,ans;
int main(void){
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].F>>a[i].S;
        if(a[i].F>a[i].S)swap(a[i].F,a[i].S);
        xma=max(xma,a[i].F);
        yma=max(yma,a[i].S);
        xmi=min(xmi,a[i].F);
        ymi=min(ymi,a[i].S);
    }
    ans=(xma-xmi)*(yma-ymi);
    sort(a,a+n);
    ll r=yma-xmi,l=1000000000;
    ll ma=0,mi=1000000000;
    ma=max(ma,a[0].S);
    mi=min(mi,a[0].S);
    n--;
    for(int i=0;i<n;i++){
        a[i].S=a[i+1].F;
        a[i].F=a[i+1].S;
    }
    sort(a,a+n,greater<P>());
    ma=max(ma,a[0].S);
    mi=min(mi,a[0].S);
    n--;
    for(int i=0;i<n;i++){
        a[i].S=a[i+1].F;
        a[i].F=a[i+1].S;
    }
    sort(a,a+n);
    l=max(ma,a[n-1].F)-min(mi,a[0].F);
    for(int i=0;i<n;i++){
        mi=min(mi,a[i].S);
        ma=max(ma,a[i].S);
        if(i+1<n)l=min(l,max(ma,a[n-1].F)-min(mi,a[i+1].F));
        else l=min(l,max(ma,a[n-1].F)-mi);
    }
    cout<<min(ans,r*l)<<endl;
}