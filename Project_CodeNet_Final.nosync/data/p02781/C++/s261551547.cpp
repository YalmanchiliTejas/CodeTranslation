#include<bits/stdc++.h>
using namespace std;
int main(){
  string s; cin>>s;
  int K; cin>>K;int k=K;
  int N=s.size();
  int64_t ans=0;
  for(int i=0;i<N;i++){
  int64_t a=s.at(i)-'0';
    if(a!=0){
      int64_t b=1;
    for(int64_t j=1;j<=K;j++)
      b=(b*(N-i-j)*9)/j;
      if(K!=1){
      int64_t c=1;
        for(int64_t j=1;j<=K-1;j++)
          c=(c*(N-i-j)*9)/j;b+=(a-1)*c;
      }
      if(K==1){b+=a-1;}ans+=b; K--; if(K==0)break;
      
    }
  }for(int i=0;i<N;i++)
    if(s.at(i)!='0')k--;
  if(k<=0)ans++;
  cout<<ans<<endl;
  return 0;
}