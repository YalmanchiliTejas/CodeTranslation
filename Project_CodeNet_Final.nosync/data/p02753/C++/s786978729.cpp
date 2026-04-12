#include <bits/stdc++.h>
using namespace std;
int main(){
    map<char, int> m;
    map<char, int>::iterator itr;
    string given;
    cin >> given;
    for(int i = 0; i < given.size(); i++){
        m[given[i]]++;
    }
    for(itr = m.begin(); itr != m.end(); itr++){
        if(itr->second > 1 && itr->second != given.size()){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}