#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> S(n);
    for (int i=0; i<n; i++) {
        cin >> S[i];
    }
    
    vector<int> alphabet(30,0);
    
    for (int i=0; i<n; i++) {
        vector<int> now_alphabet(30,0);
        for (int j=0; j<S[i].length(); j++) {
            now_alphabet[S[i][j]-'a']++;
            //cout << S[i][j]-'a' <<endl;
        }
        if (i==0) {
            for (int j=0; j<30; j++) {
                alphabet[j]=now_alphabet[j];
            }
        }
        else{
            for (int j=0; j<30; j++) {
                if (alphabet[j]>now_alphabet[j]) {
                    alphabet[j]=now_alphabet[j];
                }
            }
        }
        
    }
    
    
    
    for (int i=0; i<30; i++) {
        for (int j=0; j<alphabet[i]; j++) {
            char moji='a'+i;
            cout << moji;
        }
    }
    cout << endl;
}
