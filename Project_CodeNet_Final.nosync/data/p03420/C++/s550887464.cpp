#include <iostream>
using namespace std;

typedef long long ll;
int main(){
  ll n,k,ans=0;
  cin>>n>>k;
  if(k==0){
    cout<<n*n<<"\n";
    return 0;
  }

  for(int b=k+1;b<=n;b++){
    ans+=(n/b)*(b-k)+ max(n%b-k+1,(ll)0);
  }
  cout<<ans<<"\n";
}
