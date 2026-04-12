#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int data[51][26] = {};
const int INF = 1 << 29;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(size_t j = 0; j < s.size(); ++j){
            ++data[i][int(s[j] - 'a')];
        }
    }
    string ans = "";
    for(int i = 0; i < 26; ++i){
        int m = INF;
        for(int j = 0; j < n; ++j){
            m = min(m, data[j][i]);
        }
        ans += string(m, char('a' + i));
        /*cout << char('a' + i) << endl;
        cout << m << endl;*/
    }
    cout << ans << endl;

    return 0;
}