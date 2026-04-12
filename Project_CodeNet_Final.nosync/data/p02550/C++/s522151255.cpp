#include <bits/stdc++.h>

using namespace std;

typedef long long int ll ;  

#define pb push_back

ll sum = 0 ;

int a[100001]={0};

int main() {
    ll x , n , m , rd , ans=0 ; 
    
    vector<ll> v ;
    
    cin>>n>>x>>m;
    
    if((x*x)==x){ cout<<n*x ; return 0 ; }
    
    rd=x ;
    
    while(!a[rd])
    {
        a[rd] = 1 , v.pb(rd) ;
        rd=(rd*rd);
        rd%=m ;
    }
    
    ll len = v.size() ;
    
    vector<ll>::iterator it ;
    
    it=find(v.begin(),v.end(),rd) ;
    
    vector<ll> v1 ;
    
    ll sum = 0 , dist = it-v.begin() ;
    
    for(int i = 0 ;i<v.size();i++){
        v[i]=(sum+=v[i]) ;
    }
    ll y ;
    
    if(dist-1<0) y=0 ;
    
    else y = v[dist-1] ;
    
    for(;it!=v.end();it++) v1.pb(*it-y) ;
    
    ll len2 = v1.size() ;
    
    if(n<=len) cout << v[n-1] ;
    
    else
    {
        //cout<<sum<<endl ;
        ans+=sum ;
        n-=len ;
        //cout<<n<<endl ;
        ans+=((n/len2)*(sum-y)) ;
        if((n%len2)!=0)ans+=v1[(n%len2)-1] ;
        cout<<ans ;
    }
}
