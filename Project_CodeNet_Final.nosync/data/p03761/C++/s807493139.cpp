#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define A 26

int main(){
    int n;
    cin >> n;
    vector<short> v(A, 50);

    string S;
    for (int i = 0; i < n; ++i){
        vector<short> tmp(A, 0);
        cin >> S;
        for (auto& c : S){
            tmp[c - 'a'] += 1;
        }

        for (int j = 0; j < A; ++j){
            v[j] = min(tmp[j], v[j]);
        }
    }

    string ans = "";
    for (int i = 0; i < A; ++i){
        for (int j = 0; j < v[i]; ++j){
            ans += (char)(i + 'a');
        }
    }

    cout << ans << endl;

    return 0;
}