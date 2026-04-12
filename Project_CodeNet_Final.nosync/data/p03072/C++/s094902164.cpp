#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,count=0;
  cin >> N;
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin >> H[i];
  }
  int highest=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
        if(H[j]>highest){
          highest = H[j];
        }
    }
    if(H[i]>=highest){
      count++;
    }
  }
  cout << count << endl;
}