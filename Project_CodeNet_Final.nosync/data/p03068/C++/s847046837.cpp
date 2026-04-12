#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {
  int N,K;
  string S;
  cin>>N>>S>>K;
  char c[N];
  for(int i=0;i<N;i++){
  	if(S[K-1]!=S[i]) c[i]='*';
    else c[i]=S[K-1];
    cout<<c[i];
  }
  cout<<endl;
}
