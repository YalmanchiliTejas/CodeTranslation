#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef vector<int> vec;
int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  c*=2;
  
  if(x==y) cout<<x*min(c,a+b);
  else if(x>y){
    cout<<min( min(x*c,a*x+b*y), y*min(a+b,c)+(x-y)*min(a,c) );
  }
  else{
    cout<<min( min(y*c,a*x+b*y), x*min(a+b,c)+(y-x)*min(b,c) );
  }
  
}