#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    int n; cin>>n;
    vector<int> ans(26,51);
    for(int i=0;i<n;i++){
        string S; cin>>S;
        vector<int> A(26,0);
        for(int j=0;j<S.size();j++){
            A[S[j]-'a']++;
        }
        for(int k=0;k<26;k++){
            ans[k]=min(ans[k],A[k]);
        }
    }

    for(int i=0;i<26;i++){
        for(int j=0;j<ans[i];j++){
            char a='a'+i;
            cout<<a;
        }
    }
    return 0;
}