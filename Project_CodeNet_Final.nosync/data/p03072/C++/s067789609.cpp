#include<bits/stdc++.h>
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)
template < typename T > std::string to_string( const T& n )
  {
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
  }
using namespace std;

const long long INF=9000000000000000;
int main(){
  int n,ans=0,x=0;
  cin>>n;
  int num[n];
  for(int i=0;i<n;i++){
    cin>>num[i];
    if(i==0){
    x=num[i];
    ans++;
    }
    else{
      if(x<=num[i]){
        ans++;
        x=num[i];
      }
    }
  }
  cout<<ans<<endl;
}
