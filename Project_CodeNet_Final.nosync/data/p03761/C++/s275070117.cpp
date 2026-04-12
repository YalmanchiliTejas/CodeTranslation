#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<vector<int>> backet(n, vector<int>(26, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < s[i].length(); j++){
            backet[i][s[i][j]-'a']++;
        }
    }

    vector<int> backet2(26, 1000);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(backet2[j] > backet[i][j]) backet2[j] = backet[i][j];
        }
    }

    string ans = "";
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < backet2[i]; j++) ans += (char)(i+'a');
    }
    cout << ans << endl;
    return 0;
}