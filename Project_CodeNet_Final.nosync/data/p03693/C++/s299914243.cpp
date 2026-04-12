#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  char r,g,b;
  cin>>r>>g>>b;
  ll ans=(r-'0')*100+(g-'0')*10+(b-'0');
  if(ans%4==0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}
