#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/
 

// void chmod(ll &M){
//     if(M >= mod) M %= mod;
//     else if(M < 0){
//         M += (abs(M)/mod + 1)*mod;
//         M %= mod;
//     }
// }

const ll mod = 1e9+7;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
 
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    multiset<int> se;

    for(int i=0; i<n; ++i){
        auto itr = se.lower_bound(a[i]);
        if(itr == se.begin()) se.insert(a[i]);
        else{
            --itr;
            se.erase(itr);
            se.insert(a[i]);
        }
    }
    
    cout << se.size() << endl;

    return 0;
}