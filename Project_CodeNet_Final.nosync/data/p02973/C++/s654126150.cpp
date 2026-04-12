#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    multiset<int> s;
    rep(i, n){
        auto itr = s.lower_bound(v[i]);
        if(itr != s.begin()){
            itr--;
            s.erase(itr);
        }
        s.insert(v[i]);
    }
    cout << s.size() << endl;
}