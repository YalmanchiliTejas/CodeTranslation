#include<bits/stdc++.h>
using namespace std;

const string ALPHABETS = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int n;
    string tmpS;
    int nalphabets[26];
    for(int i=0;i<26;i++) nalphabets[i] = 1e5;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmpS;
        int tmpnalphabets[26] = {};
        for(auto s: tmpS) tmpnalphabets[s - 'a']++;
        for(int j=0;j<26;j++) nalphabets[j] = min(nalphabets[j], tmpnalphabets[j]);
    }

    for(int i=0;i<26;i++){
        for(int j=0;j<nalphabets[i];j++){
            cout << ALPHABETS[i];
        }
    }
    cout << endl;

    return 0;
}