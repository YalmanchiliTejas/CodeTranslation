#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n, m;
 
  while(cin >> n >> m, (n | m)){
    int N = n+m, arr[N];
    for(int i = 0 ; i < N ; i++){
      cin >> arr[i];
    }
    sort(arr, arr+N);
 
    int max = arr[0];
    for(int i = 0 ; i < N ; i++){
      max = std::max(max, arr[i] - arr[i-1]);
    }
    cout << max << endl;
  }
 
  return 0;
}