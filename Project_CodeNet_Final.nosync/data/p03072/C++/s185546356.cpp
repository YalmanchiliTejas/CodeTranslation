#include<bits/stdc++.h>
#include<algorithm>
#include<string>
#include<vector>
#include<tuple>
using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  int honmei=0;

  for(int i=0; i<n; i++){
    int count=0;
    for(int j=0;j<=i; j++){
      if(v[j]<=v[i]) count++;
      if(count == i+1) honmei++;
    }
  }
    cout << honmei << endl;
}
