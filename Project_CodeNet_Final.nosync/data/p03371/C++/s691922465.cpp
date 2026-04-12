#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 120
typedef long long ll;

int main(){
  ll ans,A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  ans=max(X,Y)*C*2;
  if(X<Y){
    swap(X,Y);
    swap(A,B);
  }
  ans=min(ans,Y*2*C+(X-Y)*A);
  ans=min(ans,A*X+Y*B);
  cout<<ans<<endl;
  
}
