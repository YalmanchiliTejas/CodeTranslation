#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  string s;
  cin >> s;
  if(s[0] == s[1] && s[1] == s[2]) cout << "No"  << endl;
  else cout << "Yes" << endl;
}