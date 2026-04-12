#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin>>N;
  vector<long> a(N);
  for(int i=0;i<N;i++) cin>>a[i];

  sort(a.begin(),a.end());
  //reverse(a.begin(),a.begin());
  vector<long> c(N);
  c[N/2]=a[0];

  int j=0,k=0;
  for(int i=0;i<N/2;i++){
    if(i%2==0){
      c[N/2-i-1]=a[N-1-j];
      c[N/2+i+1]=a[N-1-j-1];
      j+=2;
    }
    else{
      c[N/2-i-1]=a[k+1];
      c[N/2+i+1]=a[k+2];
      k+=2;
    }
  }
  long ans1=0;
  for(int i=0;i<N-1;i++) ans1+=abs(c[i+1]-c[i]);

  reverse(a.begin(),a.end());

  //vector<long> c(N);
  c[N/2]=a[0];

  j=0,k=0;
  for(int i=0;i<N/2;i++){
    if(i%2==0){
      c[N/2-i-1]=a[N-1-j];
      c[N/2+i+1]=a[N-1-j-1];
      j+=2;
    }
    else{
      c[N/2-i-1]=a[k+1];
      c[N/2+i+1]=a[k+2];
      k+=2;
    }
  }
  long ans2=0;
  for(int i=0;i<N-1;i++) ans2+=abs(c[i+1]-c[i]);

  cout<<max(ans1,ans2)<<endl;
  }
