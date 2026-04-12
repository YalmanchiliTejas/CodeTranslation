#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  int p[26];
  for(int i=0;i<26;i++) p[i]=50;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    for(int j='a';j<='z';j++){
      int tmp=0;
      for(int k=0;k<s.size();k++){
        if(s[k]==j) tmp++;
      }
      if(p[j-'a']>tmp) p[j-'a']=tmp;
    }
  }

  for(int i=0;i<=25;i++){
    char a='a'+i;
    for(int j=0;j<p[i];j++){
      cout<<a;
    }
  }
  cout<<endl;

  return 0;
}
