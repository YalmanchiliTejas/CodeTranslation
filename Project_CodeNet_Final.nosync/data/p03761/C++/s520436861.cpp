#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main (){
    int n;
    int data[50][26];
    int result[26];
    string c;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        for (int j = 0; j < 26; j++)
            data[i][j] = 0;
        for (int j = 0; j < s.size(); j++) {
            data[i][s[j] - 'a']++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        int minimal = 999999;
        for (int j = 0; j < n; j++) {
            if (data[j][i] < minimal)
                minimal = data[j][i];
        }
        result[i] = minimal;
        while (result[i] > 0) {
            c += ('a' + i);
            result[i]--;
        }
    }
    cout << c;
}
