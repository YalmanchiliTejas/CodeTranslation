#include <bits/stdc++.h>
#include <map> // pair
using namespace std;

typedef long long ll;
#define vec vector<int>
#define vecll vector<ll>
#define vpair vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,n)   for(int i=(int)0; i<(int)n; i++)
#define llrep(i,n)   for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n) for(int i=(int)m; i<(int)n; i++)
#define all(var)     (var).begin(), (var).end()
#define prt(var)     cout << var << endl
#define prt_dbl(i,var) cout<<fixed<<setprecision(i)<<var<<endl;
template <typename Val>
Val gcd(Val a, Val b) {
//use ll or int for gcd
    if (b==0) return a;
    else return gcd(b, a%b);
}
template <typename Val>
Val vec_max(vector<Val> v){
  return *max_element(v.begin(),v.end());
}
template <typename Val>
Val vec_min(vector<Val> v){
  return *min_element(v.begin(),v.end());
}



//---------------------------------------------------------------

int main(){
  int N;
  cin>>N;
  string S;
  vector<vector<int>>T(N,vector<int>(26,0));
  rep(i,N){
    cin>>S;
    sort(S.begin(),S.end());
    rep(j,S.size()){
      T.at(i).at(S.at(j)-'a')++;
    }
  }
  vector<int>A(26,100);
  rep(i,N){
    rep(j,26){
      A.at(j)=min(T.at(i).at(j),A.at(j));
    }
  }
  string ans;
  rep(j,26){
    if(A.at(j)>1){
      rep(i,A.at(j)){
        ans.push_back('a'+j);
      }
    }else if(A.at(j)==1){
      ans.push_back('a'+j);
    }

  }

  cout<<ans<<endl;

}
