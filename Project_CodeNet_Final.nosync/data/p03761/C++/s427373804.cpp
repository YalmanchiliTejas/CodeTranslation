#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string S;
    int minchar;

    vector<vector<int>> combi(n,vector<int>(26,0));
    for(int i=0;i<n;i++) {
        cin >> S;
        for(int j=0;j<S.size();j++) {
            combi[i][S[j]-'a']++;
        }
    }

    // アルファベット順に
    for(int i=0;i<26;i++) {
        minchar = 50;
        for(int j=0;j<n;j++) {
            if(minchar > combi[j][i]){
                minchar = combi[j][i];
            }
        }

        for(int k=0;k<minchar;k++) {
            printf("%c",'a' + i);
        }
    }

    cout << "\n";

    return 0;
}
