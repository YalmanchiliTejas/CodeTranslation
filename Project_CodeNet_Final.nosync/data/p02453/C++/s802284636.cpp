#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int n,m,a,b;
  vector<int> vec;
  
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a;
    vec.push_back(a);
  }
 
  cin >> m;
  for(int i=0;i<m;i++){
    cin >> b;
    cout << lower_bound(vec.begin(),vec.end(),b)-vec.begin() << endl;
  }

  return(0);
}

