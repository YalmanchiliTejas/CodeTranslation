#include<iostream>
#include<string>
#include<algorithm>
#include <stdio.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<array>
#include<vector>
#include<set>
#include <utility>
#include <map>
using namespace std;

int main(){
  int n; cin>>n;
   string s; cin >>s;
  int k; cin >>k;

  char f=s[k-1];

  for(int i=0;i<n;i++){
    if(s[i]!=f)s[i]='*';
  }
  cout<<s<<endl;
}
