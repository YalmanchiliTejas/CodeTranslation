#include <bits/stdc++.h>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const ll MOD = 1e9+7;

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"[";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"]";return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&p)
{o<<"{"<<p.first<<", "<<p.second<<"}";return o;}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj)
{o<<"{";for(auto itr=obj.begin();itr!=obj.end();++itr)o<<(itr!=obj.begin()?", ":"")<<*itr;o<<"}";return o;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n,a;
  cin >> n;
  multiset<int> ms;
  cin >> a;
  ms.insert(a);

  for(int i=1; i<n; i++){
    cin >> a;
    if ( a <= *ms.begin()){
      ms.insert(a);
    }else{
      auto it = ms.lower_bound(a);
      it--;
      int t = *it;
      ms.insert(a);
      ms.erase(ms.find(t));
    }
  }
  cout << ms.size() << endl;

  return 0;
}
