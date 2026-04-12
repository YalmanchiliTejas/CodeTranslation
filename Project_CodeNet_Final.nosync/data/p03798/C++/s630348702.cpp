#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < 4; ++i){
        vector<bool> is_wolf(n);
        is_wolf.at(0) = i % 2;
        is_wolf.at(1) = i / 2;
        for(int j = 2; j < n; ++j){
            if(is_wolf.at(j - 1)){
                if(s.at(j - 1) != 'o'){
                    is_wolf.at(j) = is_wolf.at(j - 2);
                }else{
                    is_wolf.at(j) = !is_wolf.at(j - 2);
                }
            }else{
                if(s.at(j - 1) == 'o'){
                    is_wolf.at(j) = is_wolf.at(j - 2);
                }else{
                    is_wolf.at(j) = !is_wolf.at(j - 2);
                }
            }
        }

        bool is_ok = true;
        for(int j = 0; j < 2; ++j){
            bool is_same = (s.at((n - 1 + j) % n) == 'o');
            if(is_wolf.at((n - 1 + j) % n)){
                is_same = !is_same;
            }
            if(is_same){
                if(is_wolf.at(n - 2 + j) != is_wolf.at(j)){
                    is_ok = false;
                }
            }else{
                if(is_wolf.at(n - 2 + j) == is_wolf.at(j)){
                    is_ok = false;
                }
            }
        }
        if(!is_ok){
            continue;
        }

        for(bool b : is_wolf){
            if(b){
                cout << 'W';
            }else{
                cout << 'S';
            }
        }
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
