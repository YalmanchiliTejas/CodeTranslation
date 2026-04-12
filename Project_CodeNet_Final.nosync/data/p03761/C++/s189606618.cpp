#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin>>n;
    vector<string> S(n);
    vector<vector<int>> N(n,vector<int>(26,0));
    for (int i=0;i<n;i++) {
        cin>>S[i];
        sort(S[i].begin(),S[i].end());
        for (int j=0;j<S[i].size();j++) {
            N[i][(S[i][j]-'a')]++;
        }
    }
    vector<int> mi(26,1e3);
    for (int i=0;i<26;i++) {
        for (int j=0;j<n;j++) {
            mi[i] = min(mi[i],N[j][i]);
        }
    }
    for (int i=0;i<26;i++) {
        for (int j=0;j<mi[i];j++) {
            cout<<char('a'+i);
        }
    }
    cout<<endl;
    return 0;
}