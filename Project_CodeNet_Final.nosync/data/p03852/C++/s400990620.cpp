#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    char c;
    cin >> c;
    string ans = "consonant";
    if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
        ans = "vowel";
    } 
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}