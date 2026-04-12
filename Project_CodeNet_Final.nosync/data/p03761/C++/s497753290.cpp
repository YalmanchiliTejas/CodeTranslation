#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    int n; cin >> n;
    map<char,int> mp;
    string s; cin >> s; 
    for(char c : s) mp[c]++;
    for(int i = 1; i < n; ++i){
        string t; cin >> t;
        map<char,int> tmp;
        for(int j = 0; j < t.size(); ++j){
            tmp[t[j]]++;
        }
        for(auto it = mp.begin(); it != mp.end(); ++it){
            it->second = min(it->second, tmp[it->first]);
        }
    }
    for(auto it = mp.begin(); it != mp.end(); ++it){
        int rep = it->second;
        for(int i = 0; i < rep; ++i){
            cout << it->first;
        }
    }
    cout << endl;
    return 0;
}
//Saw the editorial