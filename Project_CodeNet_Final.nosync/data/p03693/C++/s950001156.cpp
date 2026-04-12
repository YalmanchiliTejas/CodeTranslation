#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string r,g,b;
  cin>>r>>g>>b;
  int s=stoi(g+b);
  if(s%4 == 0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}