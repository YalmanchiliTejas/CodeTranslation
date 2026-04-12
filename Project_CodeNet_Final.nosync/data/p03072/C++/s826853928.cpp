#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  int count=0;
  int flag = 0;
  cin >> N;
  
  vector<int> a(N);
  
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  
  for(int i=1;i<N;i++){
    flag = 0;
    for(int j=(i-1);j >=0 ;j--){
      if(a[i] >= a[j]){
        flag++;
      }
    }
    if(flag == i){
      count++;
    }
  }
  cout << count+1 << endl;
}
  