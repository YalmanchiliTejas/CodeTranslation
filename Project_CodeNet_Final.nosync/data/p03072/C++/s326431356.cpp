#include <iostream>
using namespace std;
int main(){
  int h[30];
  int v[30];
  int n,c;
  for (int i=0; i<20; i++)
    v[i]=1;
  cin >> n;
  for (int i=0; i<n; i++)
    cin >> h[i];
  for (int j=1;j<n; j++){
    for (int i=0; i<j; i++){
      if (h[i] > h[j]){
        v[j] = 0;
        break;
      }
    }
  }
  c=0;
  for(int i=0; i<n; i++)
    c+=v[i];
  cout << c << endl;
}