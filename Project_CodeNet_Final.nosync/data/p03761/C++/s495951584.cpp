#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

signed main(){
    int n; cin >> n;
    vector<string> S(n);
    for(int i=0; i<n; ++i) cin >> S[i];
    int C[26];
    for(int c='a'; c<='z'; ++c){
        int count = 1<<20;
        for(int i=0; i<n; ++i){
            int tmp = 0;
            for(int j=0; j<S[i].size(); ++j){
                if(S[i][j]==c){
                    //cout << "kiteru?";
                    tmp++;
                }
            }
            count = min(count, tmp);
        }
        //cout << count << endl;
        C[c-'a'] = count;
    }
    //for(int i=0; i<26; ++i) cout << C[i] << endl;
    vector<char> res;
    for(int i=0; i<26; ++i){
        for(int j=0; j<C[i]; ++j){
            res.push_back(static_cast<char>(i+'a'));
        }
    } 
    for(int i=0; i<res.size(); ++i) cout << res[i];
    cout << endl;
    return 0;
}