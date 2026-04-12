#include<bits/stdc++.h>
typedef long long ll;
#define REP(i,n) for(int i = 0;i < (n);i++)
using namespace std;
const ll INF = 1e10;
int a,b,c,x,y,tmp;
vector<int> m(105);
int main(){
  cin>>a>>b>>c>>x>>y;
  
  if(x>y){
    tmp=y;
    y=x;x=tmp;
    tmp=b;
    b=a;a=tmp;
  }
    
  cout<<min(min(y*2*c,x*a+y*b),x*2*c+(y-x)*b)<<endl;
  
  return 0;
}