#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
 int n,k;
  string s;
  cin >> n >> s >> k;
  r(i,n){
    if(s.at(i)==s.at(k-1))cout << s.at(i);
    else cout << "*";
  }
  cout <<endl;
}