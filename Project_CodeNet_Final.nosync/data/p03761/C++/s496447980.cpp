#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define rep(i,a) for(int i = 0 ; i < a ; i ++)
#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
using namespace std;

int main(){
  int n;
  cin>>n;

  vector<vi > a(n,vi(26,0));
  string in;

  rep(i,n){
    cin>>in;
    rep(j,in.size()){
      a[i][in[j]-'a'] ++;
    }
  }
  string ret = "";
  rep(i,26){
    int r = in.size();
    rep(j,n){
      r = min(r, a[j][i]);
    }
    // cout<<char(i + 'a')<< ' ' << r<<endl;
    rep(k,r)ret += char(i + 'a');
  }
  cout<<ret<<endl;

}