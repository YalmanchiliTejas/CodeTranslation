#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;

int main() {
  char a;
  cin>>a;
  char x[5]={'a', 'i', 'u', 'e', 'o'};
  bool frag = false;
  rep(i, 5) if (x[i]==a) frag = true;
  if (frag) cout<<"vowel"<<endl;
  else cout<<"consonant"<<endl;
}
