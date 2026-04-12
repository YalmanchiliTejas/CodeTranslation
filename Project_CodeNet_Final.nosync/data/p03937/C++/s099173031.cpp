#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[2] = {0, 1};
ll dy[2] = {1, 0};

int main(void){
    ll h, w;
    cin >> h >> w;
    string s[h];
    for(ll i = 0; i < h; i++)
        cin >> s[i];
    ll count = 0;
    bool ans = true;
    for(ll i = 0; i < h; i++){
        ll check = 0;
        for(ll j = 0; j < w; j++){
            if(s[i][j]=='#') {
                count++;
                check++;
            }
        }
        if(check == 0)
            ans = false;
    }
    if(count!=h+w-1) ans = false;
    if(ans==true)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
