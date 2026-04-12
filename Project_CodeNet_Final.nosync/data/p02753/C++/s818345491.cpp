#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(void){
  int i,j,k; 
  int n;
  string s1;
  cin>>s1;
  sort(s1.begin(), s1.end());
  s1.erase(unique(s1.begin(), s1.end()), s1.end());
  if(s1.size()==2)cout<<"Yes";
  else cout<<"No";
}