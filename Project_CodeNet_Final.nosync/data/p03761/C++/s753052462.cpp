/**
 * C - 怪文書 / Dubious Document
 * https://atcoder.jp/contests/abc058/tasks/arc071_a
 **/
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
    int n; cin >> n;
    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    map<char, int> m;
    for(int i=0; i<n; i++) {
        // O(N)
        map<char, int> tmp;
        string si; cin >> si;
        for(auto c:si) {
            if(tmp.count(c)==0) {
                tmp[c] = 1;
            } else {
                tmp[c] += 1;
            }
        }
        for(auto a:alphabets) {
            // O(26)
            if(m.count(a)==0) {
                m[a] = tmp[a];
            } else {
                m[a] = min(m[a], tmp[a]);
            }
        }
    }
    for(auto ci:m) {
        for(int i=0; i<ci.second; i++) cout << ci.first;
    }
    cout << endl;
}