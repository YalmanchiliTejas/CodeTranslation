#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
typedef long long int ll;
const int MOD = 1000000007;

int main(){
    int n;
    int a[n][26] = {};
    string ans;

    cin >> n;
    for(int i=0; i < n; i++){
        for(int j=0; j < 26; j++){
            a[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<=s.size(); j++){
            char c = s[j];
            a[i][c - 'a']++;
            // cout << c - 'a' << endl;
        }
        // cout << s.size() << endl;
    }
    for(int i = 0; i < 26; i++){
        int mn = 100;
        for(int j = 0; j < n; j++){
            if(a[j][i] < mn){
                mn = a[j][i];
            }
        }
        for(int k=0; k < mn; k++){
            ans += char(i + 'a');
        }
      }

    cout << ans << endl;
    return 0;
}