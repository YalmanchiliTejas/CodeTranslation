#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  string s;
  cin >> n >> s >> k;
  char S = s.at(k-1);
  for(int i = 0; i < n; i++){
    if(s.at(i) == S){
      cout << S;
    }
    else{
      cout << '*';
    }
  }
}
