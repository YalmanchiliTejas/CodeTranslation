#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      string a,b,c;cin >> a >> b >> c;
      if(stoi(a + b + c) % 4 == 0)cout << "YES";
      else cout << "NO";
}