#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
template <typename T>
T sq(T x){
  return x * x;
}

signed main (){
  char c;
  cin >> c;

  if(c == 'a' || c == 'i' ||c == 'u'||c == 'e' ||c =='o'){

cout << "vowel" <<endl;

  }else{

cout << "consonant" << endl;

  }
    return 0;
}
