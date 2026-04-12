#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<string>S(n);
    for(int i=0;i<n;i++){
        cin >> S[i];
        sort(S[i].begin(),S[i].end());
    }
    vector<vector<int>>c(26,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<S[i].size();j++){
            c[S[i][j]-'a'][i]++;
        }
    }
    for(int i=0;i<26;i++){
        sort(c[i].begin(),c[i].end());
    }
    string ans;
    for(int i=0;i<26;i++){
        for(int j=0;j<c[i][0];j++){
            ans+='a'+i;
        }
    }
    cout << ans << endl;
}