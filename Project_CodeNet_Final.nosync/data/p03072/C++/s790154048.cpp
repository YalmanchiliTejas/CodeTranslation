#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, count=0;
  cin >> n;
  vector<int> s(n);
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      if(s[i]>=s[j]){
        if(j==i){
          count+=1;
        }
      }else{
        break;
      }
    }
  }
  cout << count << endl;
}
    