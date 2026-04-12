#include<bits/stdc++.h>
using namespace std;
int main(){
  long long K,A,B;
  cin>>K>>A>>B;
  if(K<=A)
    cout<<1<<endl;
  else if(A<=B)
    cout<<-1<<endl;
  else
    cout<<(K-B-1)/(A-B)*2+1<<endl;
}