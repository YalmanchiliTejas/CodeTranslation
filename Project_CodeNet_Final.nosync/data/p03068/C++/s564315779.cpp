#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
using namespace std;
#define MAX 1000000007
typedef long long ll;

int main(){
  int n,k;
  string s;
  cin>>n>>s>>k;

  for(int i=0;i<s.size();i++){
    if(s[i]!=s[k-1]) s[i]='*';
  }
  cout<<s<<endl;
}
