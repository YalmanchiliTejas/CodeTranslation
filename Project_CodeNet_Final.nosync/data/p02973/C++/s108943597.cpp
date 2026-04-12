#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define tll tuple<ll, ll, ll>
#define all(c) c.begin(),c.end()

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
 
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;

char albt[26] = {'a','b','c','d','e','f','g','h','i','j','k','l',
                 'm','n','o','p','q','r','s','t','u','v','w','x',
                 'y','z'};

//vector<ll> g[202020];
//fill(score, score+202020, 0);
//vector<ll> v;

int main(){
  ll n;
  cin >> n;
  vector<ll> v;
  ll aa;
  cin >> aa;
  v.push_back(aa);
  for(int i=1;i<n;i++){
    ll tmp;
    cin >> tmp;
    //DEBUG(tmp);
    auto pos = lower_bound(v.begin(),v.end(),tmp);
    if (pos == v.end()) v.back() = tmp;
    else{
      ll dis = distance(v.begin(),pos);
      //cout << tmp << " " << dis << endl; 
      if (dis == 0) v.insert(v.begin(),tmp);
      else v[dis-1] = tmp;
    }
  }

  //for (int i=0;i<v.size();i++) cout << v[i] << " ";
  //cout << endl;
  cout << v.size() << endl;
}