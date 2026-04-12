#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin>>N;
  int A[N];
  for (int i=0;i<N;i++){
    cin>>A[i];
  }
  int ns=N/2;
  int mi[N];
  int ma[N];
  for (int i=0;i<N;i++){
    mi[i]=A[i];
    ma[i]=A[i];
  }
  sort(mi,mi+N);
  sort(ma,ma+N,greater<int>());
  long s=0;
  for (int j=0;j<ns;j++){
    if (j==0){
      s+=ma[j]-mi[j];
    }
    else {
      s+=ma[j-1]-mi[j];
      s+=ma[j]-mi[j-1];
    }
  }
  int b,c;
  if (N%2!=0){
    b=ma[ns-1]-mi[ns];
    c=ma[ns]-mi[ns-1];
    if (b>c){
      s+=b;
    }
    else{
      s+=c;
    }
  }
  cout<<s;
  return 0;
}