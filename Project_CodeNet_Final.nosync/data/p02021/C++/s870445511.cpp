#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
#define lps(i,j,n) for(int i=j;i<n;i++)
#define fordebug int hoge;cin>>hoge;
#define DEKAI 1000000007;
#define INF (1<<28)
#define int long long
#define double long double
#define floot10 cout<<fixed<<setprecision(10)



signed main(){
  int n;
  cin>>n;
  int l=0,r=10000;
  int m;
  int a[100];
  lp(i,n){
    cin>>a[i];
  }
  lp(z,30){
    m=(l+r)/2;
    int cnt=0;
    bool check=true;
    lp(i,n){
      cnt+=a[i];
      cnt-=m;
      if(cnt<0){
	check=false;
      }
    }
    if(check==true){
      l=m;
    }
    else{
      r=m;
    }
  }
  m++;
  while(1){
    int cnt=0;
    bool check=true;
    lp(i,n){
      cnt+=a[i];
      cnt-=m;
      if(cnt<0){
	check=false;
      }
    }
    if(check==true){
      cout<<m<<endl;
      return 0;
    }
    else{
      m--;
    }
  }
  return 0;
}


