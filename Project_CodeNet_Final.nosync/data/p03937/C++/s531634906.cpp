#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <queue>
#include <utility>
#include <functional>
#include <sstream>
using namespace std;
#define ll long long
 
int main(void){
    ll h, w;
    cin >> h >> w;
    string s[h];
    for(ll i = 0; i < h; i++)
            cin >> s[i];
    ll count = 0;
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++){
            if(s[i][j]=='#')
                count++;
        }
    }
    if(count == h+w-1)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}