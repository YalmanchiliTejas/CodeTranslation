#include<bits/stdc++.h>
using namespace std;
int64_t N,X;
int64_t solve(int64_t n,int64_t x){
if(n==0 && x==1)
  return 1;
  else{
  if(x==1)
    return 0;
    else if(2<=x && x<=pow(2,n+1)-2)
      return solve(n-1,x-1);
    else if(x==pow(2,n+1)-1)
      return pow(2,n);
    else if(pow(2,n+1)<=x && x<=pow(2,n+2)-4)
      return pow(2,n)+solve(n-1,x+1-pow(2,n+1));
      else
        return pow(2,n+1)-1;
  }

}
int main(){
  cin>>N>>X;
  int64_t ans=solve(N,X);
  cout<<ans<<endl;
  return 0;
}