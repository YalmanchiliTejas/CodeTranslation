#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int mh=0;
  int H[N];
  int sum=0;
  for (int i=0;i<N;i++){
    cin >> H[i];
    if(H[i]>=mh){
      mh=H[i];
      sum+=1;
    }
  }
  cout << sum << endl;
}