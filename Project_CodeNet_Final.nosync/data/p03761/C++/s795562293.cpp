#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> alpha(26, 50);
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        vector<int> used(26,0);
        for(int j=0; j<s.size(); j++){
            used.at(s.at(j)-'a')++;
        }
        for(int j=0; j<26; j++){
            alpha.at(j) = min(alpha.at(j), used.at(j));
        }
    }
    for(int i=0; i<26; i++){
        //cout << alpha.at(i) << " ";
        for(int j=0; j<alpha.at(i); j++){
            cout << (char)(i+'a');
        }
    }
    cout << endl;
}