#include "bits/stdc++.h"
using namespace std;
#define REP(i, n) for(ll i = 0;i < n;i++)
#define ll long long
#define MOD 1000000007LL
using vi = vector<ll>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
using vvvi = vector<vvi>; // intの2次元の型に vvi という別名をつける
const ll llMAX=9223372036854775807LL; 
const ll llMIN=-9223372036854775808LL;

ll n,x,m;

int main(){
  ll ans=0;
  cin >> n>>x>>m;
  vi a(m*2+1);
  vi sued(m*2+1);

  a[0]=x;
  sued[a[0]]++;
  ll repnum_start=0;
  ll repnum_end=0;
  

  for(ll i=1;i<m*2;i++){
    
    a[i]=a[i-1]*a[i-1]%m;
    
    if (sued[a[i]]==1)
    {
      repnum_end=i;
      for(ll j=0;j<repnum_end;j++){
        if (a[j]==a[i]){
          repnum_start=j;
          break;
        }
      }
      break;
    }
    
    sued[a[i]]++;
    /*
    if (a[i]==a[0]){
      repnum=i;
      break;
    }
    */
  }
  
/*
  cout<<repnum_start<<endl;
  cout<<repnum_end<<endl;
*/
  if (n<=repnum_end){

    for(ll i=0;i<n;i++){
      ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
  }


  ll onesum=0;
  for(ll i=repnum_start;i<repnum_end;i++){
    onesum+=a[i];
  }
  for(ll i=0;i<repnum_start;i++){
    ans+=a[i];
  }

  n-=repnum_start;
  ll repnum=repnum_end-repnum_start;
  ll nn=n/repnum;

  ans+=nn*onesum;

  n-=nn*repnum;

  for(ll i=repnum_start;i<(repnum_start+n);i++){
    ans+=a[i];
  }

  cout<<ans<<endl;
  return 0;
}