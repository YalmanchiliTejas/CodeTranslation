#include <bits/stdc++.h>
using namespace std;
#define fol(i,n) for(int i=0;i<n;++i)
#define pb push_back
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vip;

int main(){
  int n;cin>>n;
  string s;cin>>s;
  int k;cin>>k;
  char l = s[k-1];
  fol(i,n){
    if(s[i]!=l){
      s[i]='*';
    }
  }
  cout << s << endl;
  return 0;
}
