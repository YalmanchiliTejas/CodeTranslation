#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> m(h, vector<ll>(w, 0));
    vector<ll> wsum(h, 0);
    vector<ll> hsum(w, 0);
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            char c;
            cin >> c;
            if(c == '#'){
                m.at(i).at(j) = 1;
                wsum.at(i) += 1;
                hsum.at(j) += 1;
            }
        }
    }

    for(int i = 0; i < h; ++i){
        if(wsum.at(i) == 0){ continue; }
        for(int j = 0; j < w; ++j){
            if(hsum.at(j) == 0){ continue; }
            if(m.at(i).at(j)){
                cout << '#';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}
