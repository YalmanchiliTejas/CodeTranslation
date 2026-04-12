#include <iostream>

using namespace std;

int main(void){
  int a[2*100000+10],b[2*100000+10],n;
  cin >> n;
  for (int i=1;i<n+1;i++) cin >> a[i];
  int s = n / 2;
  int d = n % 2;
  if(d==0){
    for(int i=1;i<s+1;i++){
      b[s+i] = a[2*i-1];
    }
    for(int i=s;i>0;i--){
      b[i] = a[n-2*i+2];
    }
  }
  else{
    for(int i=1;i<s+1;i++){
      b[s+1+i] = a[2*i];
    }
    for(int i=s+1;i>0;i--){
      b[i] = a[n-2*i+2];
    }
  }
  for (int i=1;i<n+1;i++) cout << b[i] << " ";
  cout << endl;
  return 0;
}
