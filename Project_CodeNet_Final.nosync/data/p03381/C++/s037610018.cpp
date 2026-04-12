#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> X(N);
  vector<long long> Xc(N);
  int loop;
  for(loop=0;loop<N;loop++){
    cin >> X[loop];
  }
  Xc=X;
  sort(Xc.begin(),Xc.end());
  long long gre=Xc[(N/2)-1],lea=Xc[(N/2)];
  for(loop=0;loop<N;loop++){
    if(X[loop]<=gre){
      cout << lea << endl;
    }else{
      cout << gre << endl;
    }
  }
  return 0;
}