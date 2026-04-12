#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  char a;
  cin>>a;
  cout<<(a=='a' || a=='i' || a=='u' || a=='e' || a=='o' ? 
         "vowel" : "consonant")<<endl;
}