#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(26,50);
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        vector<int> ta(26);
        for(int j = 0; j < tmp.size(); j++) {
            ta[tmp[j]-'a']++;
        }
        for(int k = 0; k < 26; k++) {
            a[k]=min(a[k],ta[k]);
        }
    }
    string ans={};
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < a[i]; j++) {
            ans+=(char)('a'+i);
        }
        //cout << (char)('a'+i) << " " << a[i] << "\n";
    }
    cout << ans << "\n";
    return 0;
}