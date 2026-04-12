#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stdlib.h>
#define INF (1e9+7)
#define distance(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
#define rep(i,N) for(ll i=0;i<N;i++)
#define rep2(i,j,k) for(ll i=j; i<k;i++)
typedef long long int ll;
using namespace std;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using vs=vector<string>;
using vvs=vector<vector<string>>;

template <typename T>
void print(T v){
    for(size_t i=0;i<v.size();i++){
        cout<<i<<": "<<v[i]<<endl;}
}

template <typename T>
void print2(T v){
    for(size_t i=0;i<v.size();i++){
        cout<<i<<": ";
        for(size_t j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

void p(vector<int> v){
    for(size_t k=0;k<v.size();k++){
        cout<<v[k]<<" ";
    }
    cout<<endl; 
}
    

int main(){    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    //vvl v(5,vl(3,-1));
    
    ll a,b,c,x,y,temp,ans;
    cin>>a>>b>>c>>x>>y;
    
    if(x<y){
        temp=a;
        a=b;
        b=temp;
        temp=x;
        x=y;
        y=temp;
    }
        
    ll ans1=c*(x*2);
    ll ans2=c*(y*2)+a*(x-y);
    ll ans3=a*x+b*y;
    
    ans=min(ans1,ans2);
    ans=min(ans,ans3);
    
    cout<<ans<<endl;
        
    
    return 0;}