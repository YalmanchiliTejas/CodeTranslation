#include <iostream>
using namespace std;
int n;
int res[26];
int main(void){
    // Your code here!
    cin >> n;
    for (int i = 0; i < n; i++) {
        int al[26];
        for (int i = 0; i < 26; i++) al[i] = 0;
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            al[str[j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (i == 0) res[j] = al[j];
            else res[j] = min(res[j], al[j]);
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < res[i]; j++) {
            printf("%c", 'a' + i);
        }
    }
}
