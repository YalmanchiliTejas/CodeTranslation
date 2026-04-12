#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  int a[200000];
  int b[200000];
  int key = 0;
  int flag;
  
  cin >> n;

  flag = n % 2;
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
  
  for(int j = n - 1;j >= 0;j -= 2){
    b[key] = a[j];
    key ++;
  }
  
  for(int j = flag;j < n;j += 2){
    b[key] = a[j];
    key ++;
  }

  for(int i = 0;i < n;i++){
    cout << b[i] << ' ';
  }

  cout << endl;
  return 0;
}
