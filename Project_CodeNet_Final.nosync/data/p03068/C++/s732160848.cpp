#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<ll>;
using P  = pair<ll,ll>;

int main(){
    int n,k;
    string s;
    cin >>n>>s>>k;
    k--;
    rep(i,n){
      if(s[i]==s[k])cout << s[i];
      else cout << "*";
    }
    cout << endl;
    return 0;
}