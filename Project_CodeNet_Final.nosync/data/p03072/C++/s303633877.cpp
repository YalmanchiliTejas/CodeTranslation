#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
  int N,cnt=0,a;
  cin>>N;
  int H[N];
  for(int i=0;i<N;i++) cin>>H[i];
  for(int i=0;i<N;i++){
    if(i==0) a=H[0];
    a=max(H[i],a);
    if(a<=H[i]) cnt++;
  }
  cout<<cnt<<endl;
}
