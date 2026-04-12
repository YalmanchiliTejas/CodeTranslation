#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
#define M 1000000007
int main(){
  int n,k;string s;
  cin>>n>>s>>k;k--;
  for(int i=0;i<n;i++){
    if(s[i]!=s[k])s[i]='*';
  }
  cout<<s;
}