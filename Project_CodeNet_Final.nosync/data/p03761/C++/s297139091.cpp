#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n; string s;
    cin >> n;

    string ans = "";
    int c1[26], c2[26] = {0};
    fill_n(c1, 26, 100);

    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            char cj = s[j];
            c2[cj-'a']++;
        }

        for(int j = 0; j < 26; j++){
            c1[j] = min(c1[j], c2[j]);
            c2[j] = 0;
        }
    }

    for(int j = 0; j < 26; j++){
        char c = 'a' + j;
        for(int k = 0; k < c1[j]; k++){
            ans += c;
        }
    }

    cout << (ans != "" ? ans : " ") << endl;
    return 0;
}