#include <bits/stdc++.h>
#define SORT(x) sort(x.begin(),x.end())
#define ALL(x) x.begin(),x.end()
#define deb(x) cout<<#x<<"="<<x<<endl
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, m, n) for(int i = m; i < n; i++)
#define repr(i, m, n) for(int i = m; i >= n; i--)
#define INF 1000000007
#define PI (acos(-1))
#define MOD 1000000007
using namespace std;
typedef long long ll;


void Main(){

  int n;
  cin>>n;
  int minword[26];
  rep(i,26){
    minword[i]=INF;
  }
  rep(i,n){
    int word[26]={};
    string ss;
    cin>>ss;
    rep(j,ss.length()){
      char c=ss[j];
      word[c-'a']++;
    }
    rep(j,26){
      minword[j]=min(minword[j],word[j]);
    }
  }

  string ans="";

  rep(i,26){
    rep(j,minword[i]){
      ans+=(char)('a'+i);
    }
  }

  cout<< ans<<"\n";

}
//-----------------------------------
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}
//-----------------------------------
