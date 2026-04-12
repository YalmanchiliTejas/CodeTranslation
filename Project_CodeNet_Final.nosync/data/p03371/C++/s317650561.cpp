#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=10000000000000000; 
ll a,b,c,x,y;
int main(){
   cin>>a>>b>>c>>x>>y;
    c*=2;
    ll sum;
    ll ab=max(x,y)*c;
    ll AB=inf;
    if(x>y){
         AB=(x-y)*a+c*y;
    }
    else if(y>x){
         AB=(y-x)*b+c*x;
    }
 sum=min(min(x*a+y*b,ab),AB);
 cout<<sum<<endl;
}