#include<iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int h[n];
  int ans=0;
  for(int i=0;i<n;i++){
    cin >> h[i];
  }
  for(int i=0;i<n;i++){
    int a=1;
    for(int j=0;j<i;j++){
      if(h[j]> h[i]){
        a=0;
        break;
      }
    }
    if(a==1) ans++;
  }

  cout << ans << endl;
}
