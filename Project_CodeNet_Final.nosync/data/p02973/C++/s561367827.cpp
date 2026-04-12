#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long>a(n);
  vector<int>colors(n,0);
  vector<long>arrayMin;
  int i,j;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  arrayMin.push_back(a[0]);
  for(i=1;i<n;i++){
    if(arrayMin[arrayMin.size()-1]>=a[i]){
      arrayMin.push_back(a[i]);
    }else{
      for(j=0;j<arrayMin.size();j++){
        if(arrayMin[j]<a[i]){
          arrayMin[j]=a[i];
          break;
        }
      }
    }
  }
  cout << arrayMin.size() << endl;

}
