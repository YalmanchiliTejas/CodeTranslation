#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> da(n);
  for(int i=0;i<n;i++)
    cin >> da[i];
  int ma=da[0],co=1;
  for(int i=1;i<n;i++){
    if(ma<=da[i]){
      co++;
      ma=da[i];
    }
  }
  cout << co << endl;
}