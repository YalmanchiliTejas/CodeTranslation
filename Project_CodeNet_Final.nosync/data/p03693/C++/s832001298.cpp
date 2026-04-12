#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  int s = 0;
  rep(i, 3){
    int x;
    cin >> x;
  	s *= 10;
    s += x;
  }
  if(s % 4 == 0){
    cout << "YES" << endl;
  } else {
  	cout << "NO" << endl;
  }
}