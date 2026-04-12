#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdexcept>
#include<stdio.h>
#include<queue>
using namespace std;

int main(){
  int n,k; string s;
  cin >> n >> s >> k;
  for(int i=0;i<s.size();i++){
    if(s[i]!=s[k-1]) s[i]='*';
  }
  cout << s <<endl;
}