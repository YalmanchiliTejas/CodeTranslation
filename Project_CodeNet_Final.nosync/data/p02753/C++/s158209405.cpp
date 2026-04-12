#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;


int main() {
  string s;
  cin>>s;
  int n=3,c=0;
  while(n--){
    if(s[n]=='A') ++c;
  }

  if(c==0 || c==3){
    cout<<"No"<<endl;
  } else {
    cout<<"Yes"<<endl;
  }
  

  return 0;
}
