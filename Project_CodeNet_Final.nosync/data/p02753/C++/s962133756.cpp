#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  if(s[0]==s[1] && s[1]==s[2]){
    cout << "No" << endl;
  }
  else cout << "Yes" << endl;
  
  
  return 0;
    

}
