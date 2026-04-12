#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int main(){
  char vowel[5]={'a','e','i','o','u'};
  char c[1];
  cin>>c[0];
  bool found=false;
  rep(i,5){
    if(c[0]==vowel[i]){found=true;}
  }
  cout<<(found?"vowel":"consonant")<<endl;
}
