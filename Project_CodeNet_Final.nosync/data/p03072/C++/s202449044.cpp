#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int H[N];
  int count=1;
  for(int i=0;i<N;i++){
    cin >> H[i];
  }
  int max=H[0];
  for(int i=0;i<N-1;i++){
    if (max<H[i])max=H[i];
    if(max<=H[i+1]){
      count++;
    }else {
      continue;
    }
  }
  cout << count << endl;
}
