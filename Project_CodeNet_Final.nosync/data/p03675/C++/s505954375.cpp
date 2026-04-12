#include<iostream>
#include<algorithm>

using namespace std;



int n;
int a[216000];
int main(){
  cin >> n;
  for(int i = 0;i < n;i++)cin >> a[i];
  int p = n - 1;
  int k = -2;
  for(int i = 0;i < n;i++){
    cout << a[p] << " ";
    p += k;
    if(p == -1 && k == -2){
      p = 0;
      k = 2;
    }
    if(p == -2 && k == -2){
      p = 1;
      k = 2;
    }
  }cout << endl;
  
  return 0;
}