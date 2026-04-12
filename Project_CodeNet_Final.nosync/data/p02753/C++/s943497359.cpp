#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  cout<<fixed;
  string s;
  cin>>s;
  int a=0,b=0;
  rep(i,s.size()) {
    if(s[i]=='A')a++;
    if(s[i]=='B')b++;
  }
  if(a==0||b==0)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}
