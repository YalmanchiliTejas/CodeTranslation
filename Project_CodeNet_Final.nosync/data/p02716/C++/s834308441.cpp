#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
#include <random>
#include <ctime>
#include <chrono>
#include <set>
using namespace std; typedef long long ll; const int INF=1e9; typedef pair<int,int> P;
struct tp{int x,y,r;}; const int up[]={1,-1,0,0}, lf[]={0,0,1,-1};
int main() {
  int n; cin>>n;
  ll a[n]; for(int i=0;i<n;i++) cin>>a[i];
  
  if (n%2==0) {
    ll an=-1e18;
    ll sm=0;
    for(int i=0;i<n;i+=2) {
      sm+=a[i];
    }
    an=max(an,sm);
    for(int i=n-1;i>0;i-=2) {
      sm-=a[i-1]; sm+=a[i];
      an=max(an,sm);
    }
    cout<<an<<endl;
  } else {
    ll an[n][3]; fill(an[0],an[n],-1e18); an[0][0]=a[0]; an[1][1]=a[1]; an[2][2]=a[2];
    for(int i=0;i<n;i++) {
      for(int j=0;j<3;j++) {
        if (i+2<n)an[i+2][j]=max(an[i+2][j], an[i][j]+a[i+2]);
        if (i+1<n && j+1<3)an[i+1][j+1]=max(an[i+1][j+1], an[i][j]);
      }
    }
    /*
    for(int j=0;j<3;j++) {
      for(int i=0;i<n;i++) {
        cout<<an[i][j]<<" ";
      } cout<<endl;
    }*/
    cout<<an[n-1][2]<<endl;
  }
}