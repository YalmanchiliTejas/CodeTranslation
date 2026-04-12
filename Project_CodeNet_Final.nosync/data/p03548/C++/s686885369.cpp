#include<iostream>
#include<algorithm>
#include<climits>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define scan(arg) cin>>arg
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
using namespace std;
typedef long long ll;
const int NMAX=1<<17;
int x,y,z;
int main(){
  scan(x);scan(y);scan(z);
  if(x%(y+z)>=z){
    prin(x/(y+z));
  }
  else{
    prin(x/(y+z)-1);
  }
    
  
  return 0;
}
