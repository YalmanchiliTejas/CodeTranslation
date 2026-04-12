#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n, mid1, mid2;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b+n);
  mid1 = b[n/2-1];
  mid2 = b[n/2];
  for (int i = 0; i < n; i++){
    if(a[i] <= mid1) cout << mid2 << endl;
    else cout << mid1 << endl;
  }
  
}
