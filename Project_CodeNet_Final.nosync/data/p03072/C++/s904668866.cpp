#include <string>
#include <bits/stdc++.h>
#include <stdio.h>
#include<math.h>
#include <ctype.h>
#include <algorithm> // sort
#include <map> // pair
using namespace std;


int main() {
 int n,ans;
  cin >> n;
  ans=1;
  
  vector<int> vec(n);
  cin >> vec.at(0);
  for(int i=1;i<n;i++){
    cin >> vec.at(i);
    bool tmp=true;
    for(int j=0;j<i;j++){
      if(vec.at(j)>vec.at(i)){
        tmp=false;
        break;
      }
    }
    if(tmp){
      ans++;
    }
  }
  cout << ans << endl;
}
    