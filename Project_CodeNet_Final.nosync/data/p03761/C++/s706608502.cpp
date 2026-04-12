#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <deque>
using ll = long long;
using namespace std;

int main(){
    vector<char> alphabet;
    for (char i = 'a'; i <= 'z' ; i++) {
        alphabet.push_back(i);
    }
    int n;
    string s;
    cin >> n;
    int ALP[n][26];
    for (int i = 0; i < n; i++) for (int j = 0; j < 26; j++) {
        ALP[i][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            int m = s[j] - 'a';
            ALP[i][m]++;
        }
    }
    int ANS[26];
    for (int j = 0; j < 26; j++) {
        int tmp, cnt = 100;
        for (int i = 0; i < n; i++) {
            tmp = ALP[i][j];
            cnt = min(cnt, tmp);
        }
        ANS[j] = cnt;
    }
    for (int i = 0; i < 26; i++) {
        int a = ANS[i];
        for (int j = 0; j < a; j++) {
            cout << alphabet[i];
        }
    }
    cout << endl;
    return 0;
}
