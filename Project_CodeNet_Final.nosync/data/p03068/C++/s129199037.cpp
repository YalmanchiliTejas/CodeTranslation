#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>

using namespace std;

int main(){
  int a, b, c;
  string s;
  int n,k;
  cin >> n >> s >> k;

  for(int i = 0; i < n ; i++){
    if(s[i] != s[k-1]) s[i] = '*';
  }
  cout << s << endl;
}
