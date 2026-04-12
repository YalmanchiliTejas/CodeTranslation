#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;cin>>s;
  char v[]={'a','i','u','e','o'};
  bool f=0;
  for(int i=0;i<(int)s.size();i++)
    for(int j=0;j<5;j++) f|=s[i]==v[j];
  cout << (f?"vowel":"consonant")<<endl;
  return 0;
}
