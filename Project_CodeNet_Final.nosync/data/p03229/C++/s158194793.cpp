#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 998244353

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  sort(A.begin(),A.end());

  vector<ll> B(N);
  int small=1;
  int large=N-1;
  int left=N/2-1;
  int right=N/2+1;
  B.at(N/2)=A.at(0);
  for(int i=1;i<N;i++){
    if(i%2==1){
      if((N/2-left)%2==1){
        B.at(left)=A.at(large);
        left--;
        large--;
      }else{
        B.at(left)=A.at(small);
        left--;
        small++;
      }
    }else{
      if((right-N/2)%2==1){
        B.at(right)=A.at(large);
        right++;
        large--;
      }else{
        B.at(right)=A.at(small);
        right++;
        small++;
      }
    }
  }

  ll ans=0;
  for(int i=0;i<N-1;i++){
    ans+=abs<ll>(B.at(i+1)-B.at(i));
  }

  reverse(A.begin(),A.end());
  small=1;
  large=N-1;
  left=N/2-1;
  right=N/2+1;
  B.at(N/2)=A.at(0);
  for(int i=1;i<N;i++){
    if(i%2==1){
      if((N/2-left)%2==1){
        B.at(left)=A.at(large);
        left--;
        large--;
      }else{
        B.at(left)=A.at(small);
        left--;
        small++;
      }
    }else{
      if((right-N/2)%2==1){
        B.at(right)=A.at(large);
        right++;
        large--;
      }else{
        B.at(right)=A.at(small);
        right++;
        small++;
      }
    }
  }
  ll sum=0;
  for(int i=0;i<N-1;i++){
    sum+=abs<ll>(B.at(i+1)-B.at(i));
  }
  ans=max<ll>(ans,sum);


  cout<<ans<<endl;
}
