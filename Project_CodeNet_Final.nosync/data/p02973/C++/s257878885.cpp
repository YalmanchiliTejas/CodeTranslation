#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
各a[i]について、集合を管理し
・集合の最小値よりも小さければ追加
・そうでなければ、その値を超えない最小の要素をa[i]に置換
*/

void solve(){
    ll n;
    cin >> n;
    ll a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    multiset<int> st;
    st.insert(a[0]);
    for(ll i=1; i<n; i++){
        if(a[i]<=*st.begin()) st.insert(a[i]);
        else{
            auto it = st.lower_bound(a[i]);
            --it;
            st.erase(it);
            st.insert(a[i]);
        }
    }

    cout << st.size() << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}