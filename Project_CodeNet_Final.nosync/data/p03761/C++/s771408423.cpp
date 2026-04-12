#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;

const int mod = 1e9+7;

int main() {
    int n;
    //char alph = {'a','b','c','d'};
    cin >> n;
    vector<vector<int>> A(26, vector<int>(n, 0));
    string S[n];
    rep(i,n) cin >> S[i];
    for(int i=0;i<n;++i) {
        for(char c:S[i]) {
            A[c-'a'][i]++;
        }
    }
    string ans = "";
    int index=0;
    for(vector<int> a:A){
        int num = *min_element(a.begin(), a.end());
        char c = 'a'+index;
        rep(i,num) ans = ans+c;
        ++index;
    }
    cout << ans << endl;

}
