#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m; i<n; i++)
#define co(n) cout << n << endl
using namespace std;
int main(){
  char a;
  cin >> a;
  if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') co("vowel");
  else co("consonant");
  return 0;
}