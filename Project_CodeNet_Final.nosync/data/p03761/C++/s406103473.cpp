#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

int main() {
    int n; cin >> n;
    vector<vector<int>> v(n,vector<int>(26));
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<s.size();j++) v[i][s[j]-'a']++;
    }
    for(int i=0;i<26;i++){
        int MIN=INFI;
        for(int j=0;j<n;j++){
            if(MIN>v[j][i]) MIN=v[j][i];
        }
        char ans='a'+i;
        for(int j=0;j<MIN;j++) cout << ans;
    }
    cout << endl;
}

