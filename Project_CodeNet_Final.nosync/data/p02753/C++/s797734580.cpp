#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }
  else{
    return gcd(b,(a%b));
  }
}
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}
ll mpower(ll a,ll b,ll c){
    int z;
    if(b==0){
        z=1;
        z%=c;
        return z;
    }
    if(b==1){
        z=a;
        z%=c;
        return z;
    }
    else{
        return (((mpower(a,b/2,c))*(mpower(a,b/2,c))%c)*mpower(a,b%2,c)%c);
    }
}

int main(){
  string a;
  cin>>a;
  if(a.at(0)==a.at(1)&&a.at(1)==a.at(2)){
    cout<<"No";
    return 0;
  }
  cout<<"Yes";
}