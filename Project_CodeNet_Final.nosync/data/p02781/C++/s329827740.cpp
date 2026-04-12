#include "bits/stdc++.h"
using namespace std;
#define REP(i, n) for(ll i = 0;i < n;i++)
#define ll long long
#define MOD 1000000007
#define llMAX 9223372036854775807
#define llMIN -9223372036854775808
using vi = vector<ll>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける

ll k,x,y;
vi a(100);

ll funck1(ll inp,ll nl){
  
  ll flag=0,ans=0;
  if (a[nl-2-inp]==0)return 0;
  
    for(ll i=inp;i<nl-1;i++){
      if (a[nl-2-i]!=0){
        flag=1;
        ans+=a[nl-2-i];
        ans+=9LL*(nl-2-i);
        break;
      }
    }
    return ans;
}


ll funck2(ll inp,ll nl){
  ll flag=0,ans=0;
  //if (a[nl-2-inp]==0)return 0;
  for(ll i=0;i<nl-1;i++){
      
      if (a[nl-2-i]!=0){
        flag++;
        if (flag==1){
          ans+=(a[nl-2-i]-1)*9LL*(nl-2-i);
          ans+=81LL*(nl-2-i)*(nl-2-i-1)/2LL;
        }

        if (flag==2){
          ans+=a[nl-2-i]+9LL*(nl-2-i);
          break;
        }
      }
    }

    if (flag>=1)return ans;
    return 0;
}

int main(){
  ll ans=0;
  string n;
  cin >> n >> k;
  ll nl=n.length();
  
  REP(i,nl){
    a[i]=n[nl-1-i]-48;
  }

  ll k9=1;
  REP(i,k){
    k9*=9;
  }

  REP(i,nl-1){
    if (i+1>=k){
      ll ii=i+1;
      ll k9a=k9;
      REP(i,k-1){
        k9a*=ii-1-i;
      }
      if (k==3)k9a/=2;
      ans+=k9a;
    }
  }


  if (k==1){
    ans+=a[nl-1];
  }


  if ((k==2)&(nl>=2)){
    ans+=(a[nl-1]-1)*9LL*(nl-1);
    ll flag=0;
    for(ll i=0;i<nl-1;i++){
      if (a[nl-2-i]!=0){
        //flag=1;
        ans+=a[nl-2-i];
        ans+=9LL*(nl-2-i);
        break;
      }
    }
    //REP(i,nl-1)
    //  ans+=funck1(i,nl);
  }


  if ((k==3)&(nl>=3)){
    ans+=(a[nl-1]-1LL)*81LL*(nl-1)*(nl-2)/2LL;
    ll flag=0;

    flag=0;
    
    ans+=funck2(0,nl);
  
  }
  
  if (nl<k)ans=0;




  cout<<ans<<endl;
  return 0;
}