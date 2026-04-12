#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/


int main(){
    int N; cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];

    multiset<int> se{a[0]};
    for(int i=1; i<N; ++i){
        auto itr = se.lower_bound(a[i]);
        if(itr == se.begin()){
            se.insert(a[i]);
        }
        else{
            itr--;
            se.erase(itr);
            se.insert(a[i]);
        }
    }


    cout << se.size() << endl;
}