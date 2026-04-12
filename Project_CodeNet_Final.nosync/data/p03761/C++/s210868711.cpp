#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define is(a, b) a == b
#define len(v) ll(v.size())

const ll mod=1e9+7;

//vector書き出し
template <class T>
void cout_vec(const vector<T> &vec1){
  rep(i,len(vec1)){
    cout<<vec1[i]<<' ';
  }
  cout<<'\n';
}

typedef pair<ll,ll> P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<string> s(n);
    rep(i,n) cin>>s[i];
    vector<map<char,int> > cnt(n);
    rep(i,n){
      rep(j,len(s[i])){
        cnt[i][s[i][j]]++;
      }
    }
    string ans;
    rep(i,26){
      char x='a'+i;
      int c=cnt[0][x];
      rep(j,n){
        if(cnt[j][x]<c){
          c=cnt[j][x];
        }
      }
      rep(i,c){
        ans.push_back(x);
      }
    }
    sort(begin(ans),end(ans));
    cout<<ans<<endl;
}