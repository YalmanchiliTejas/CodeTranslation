#include<bits/stdc++.h>

#define rep(i, a, n)  for(ll i=a; i<n; i++)
#define per(i, a, n)  for(ll i=n-1; i>=a; i--)
#define fill0(n)  setfill('0') << right << setw(n)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LONGMAX 1e18
#define INTMAX 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

int n;
string s[100];
map<char, int> canuse, used;
vector <int> v(26,0);

int main(){
  cin >> n;
  cin >>  s[0];
  rep(i,0,s[0].size()) v[s[0][i]-'a']++;
  rep(i,1,n){
    map<char, int> temp;
    cin >> s[i];
    rep(j,0,s[i].size())temp[s[i][j]]++;
    rep(j,0,26){
      v[j] = min(v[j], temp[j+'a']);
    }
  }
  string ans="";
  for(int i=0;i<26;i++){
    int a = v[i];
    if(a!=0){
      rep(j,0,a)ans +=(i+'a');
    }
  }
  cout << ans <<endl;

}
