#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int H[21];
  cin >> N;
  H[0]=0;
  for(int i=1; i<=N; i++) cin >> H[i];
  int sum=0;
  for(int i=1; i<=N; i++){
    int add=1;
    for(int j=0; j<i; j++){
      if(H[j]>H[i]) add=0;
    }
    sum+=add;
  }
  cout << sum << endl;
}