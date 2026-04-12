#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
#define PI 3.14159265359
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
typedef long long ll;

int main() {
  string s;
  cin >> s;
  if(s.at(0)==s.at(1)&&s.at(1)==s.at(2)){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}
