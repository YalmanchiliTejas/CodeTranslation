#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void){
    int n, a[55][26];
    string s;
    cin >> n;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) a[j][i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            a[i][char(s[j]) - 'a']++;
            //cout << a[i][char(s[j]) - 'a'] << endl;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        int mn = 100;
        for (int j = 0; j < n; j++) {
            mn = min(mn, a[j][i]);
        }
        for (int j = 0; j < mn; j++) cout << char(i + 'a');
    }
    cout << endl;
    
    
}
