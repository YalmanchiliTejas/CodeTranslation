#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

ll n;
vector<pll> A;



ll cul2(){
    ll mi=E;
    vector<ll> used(n,0);
    ll f=0;
    ll cnt=0;
    ll r=1;
    while(r+1<2*n && f<2){
        if(A[r].S==A[0].S || A[r].S==A.back().S){f++;}
        if(!used[A[r].S]){cnt++;}
        used[A[r].S]++;
        r++;
    }
    for(ll i=1;i+1<2*n;i++){
        while(r+1<2*n && cnt<n){
            if(!used[A[r].S]){cnt++;}
            used[A[r].S]++;
            r++;
        }
        if(f<2 || cnt<n){break;}
        mi=min(mi,A[r-1].F-A[i].F);
        if(A[i].S==A[0].S || A[i].S==A.back().S){break;}
        if(used[A[i].S]==1){cnt--;}
        used[A[i].S]--;
    }
    return mi*(A.back().F-A[0].F);
}




int main(){
    cin>>n;
    A.resize(2*n);
    ll mx2=-E,mx1=-E,mi2=E,mi1=E;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        if(x>y){swap(x,y);}
        A[i]={x,i};
        A[i+n]={y,i};
        mx2=max(mx2,y);
        mx1=max(mx1,x);
        mi2=min(mi2,y);
        mi1=min(mi1,x);
    }
    sort(A.begin(),A.end());
    ll ans=(mx2-mi2)*(mx1-mi1);
    if(A[0].S!=A.back().S){ans=min(ans,cul2());}
    cout<<ans<<endl;
    
    
    
    return 0;
}
