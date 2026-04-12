#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    REP(i, h){
        cin >> a.at(i);
    }

    ll i = 0, j = 0;
    a.at(i).at(j) = '.';
    while(true){
        const vector<ll> di = {-1, 1, 0, 0};
        const vector<ll> dj = {0, 0, -1, 1};
        ll count = 0;
        ll nxt_idx = -1;
        REP(k, 4){
            if(i + di.at(k) < 0 || i + di.at(k) >= h ||
               j + dj.at(k) < 0 || j + dj.at(k) >= w){
                continue;
            }
            if(a.at(i + di.at(k)).at(j + dj.at(k)) == '#'){
                count++;
                nxt_idx = k;
            }
        }
        if(count >= 2 ||
           (count == 1 && (nxt_idx == 0 || nxt_idx == 2))){
            cout << "Impossible" << endl;
            return 0;
        }else if(count == 0){
            break;
        }else{
            a.at(i + di.at(nxt_idx)).at(j + dj.at(nxt_idx)) = '.';
            i = i + di.at(nxt_idx);
            j = j + dj.at(nxt_idx);
        }
    }
    cout << "Possible" << endl;
    return 0;
}
