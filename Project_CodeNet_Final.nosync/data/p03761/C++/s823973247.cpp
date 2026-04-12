#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> ss(n, vector<int>(26));
    for(int i=0; i<n; ++i){
        string s; cin >> s;
        for(auto c : s){
            ++ss[i][c-'a'];
        }
    }
    for(int i=0; i<26; ++i){
        int num=INT_MAX;
        for(int j=0; j<n; ++j){
            num=min(num, ss[j][i]);
        }
        for(int j=0; j<num; ++j){
            cout << (char)(i+'a');
        }
    }
    cout << endl;
    return 0;
}
