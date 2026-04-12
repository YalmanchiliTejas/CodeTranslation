#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define F first
#define S second
int n,ans;
ll s;
map<ll,int> m;
int main(void){
    scanf("%d",&n);
    m.insert(P(ll(0),0));
    for(int i=1;i<=n;i++){
        ll a;
        scanf("%lld",&a);
        s+=a;
        if(m.find(s)==m.end())m.insert(P(s,i));
        else ans=max(ans,i-m[s]);
        
    }
    printf("%d\n",ans);
}

