#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  int ans = 0;
  for(int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
  }
  vector<int> array(N);
  for(int i = 0; i < N; i++) {
    array[i] = i + 1;
  }
  
  int next = 0;
  bool flag;
  do {
    flag = true;
    if(array[0] != 1) continue;
    next = 1;
    for(int i = 0; i < N - 1; i++) {
      if(next != array[i]) { flag = false; break; }
      for(int j = 0; j < M; j++) {
        if(a[j] == array[i] && array[i + 1] == b[j]) next = b[j];
        else if(b[j] == array[i] && array[i + 1] == a[j]) next = a[j];
      }
    }
    if(next == array[N - 1] && flag == true) ans++;
     

  }while(next_permutation(array.begin(), array.end()));
 

 cout << ans;
 return 0;
}