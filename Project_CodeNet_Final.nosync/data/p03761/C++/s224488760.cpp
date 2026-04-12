#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <map>
#include <set>
#include <ios>
#include <iomanip>
#include <functional>
#include <queue>

#define int long long

int inf = (1LL <<  62);
using namespace std;

signed main(){
    map<int, int> mp;
    int n;
    cin >> n;
    for(int i = 0; i < 26; i++){
        mp[i] = inf;
    }
    vector<string> sv;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        sv.push_back(s);
    }
    
    for(int i = 0; i < n; i++){
        vector<int> v(26, 0);
        for(int j = 0; j < sv[i].size(); j++){
            v[sv[i][j] - (int)('a')]++;
        }
        for(int j = 0; j < 26; j++){
            if(mp[j] > v[j]){
                mp[j] = v[j];
            }
        }
    }
    
    char alf[26] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
    
    string s = "";
    
    for(int i = 0; i < 26; i++){
        if(mp[i] != inf && mp[i] != 0){
            for(int j = 0; j < mp[i]; j++){
                s += alf[i];
            }
        }
    }
    cout << s;
}