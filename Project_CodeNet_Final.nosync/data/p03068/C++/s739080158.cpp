#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>

using namespace std;


int main(){
  int n, k;
  char a;
  string s;
  cin >> n >> s >> k;
  a = s[k - 1];


  for(int i = 0; i < n; ++i){
    if(s[i] != a){
      s[i] = '*';
    }
  }
  cout << s << endl;
}
