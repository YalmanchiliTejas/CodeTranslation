#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
int n, cnt;
int has[51][27];
string s;
const int inf = 1e9;
int main(int argc, const char * argv[]){
    cin>>n;
    vector<string> vec(n);
    map<char, int> loc;
    cnt = 0;
    for(char c = 'a'; c <= 'z'; ++c){
        loc[c] = cnt++;
    }
    for(int i = 0; i < n; ++i){
        cin>>s;
        vec[i] = s;
        for(int j = 0; j < (int)s.size(); ++j){
            has[i][loc[s[j]]]++;
        }
    }
    
    // 1: 2 1 1
    // 2: 2 0 2 1
    // 3: 3 0 3
    
    
    vector<int> res(26, inf);
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < n; ++j){
            res[i] = min(has[j][i], res[i]);
        }
    }
    string t = "";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < res[i]; ++j){
            t += alphabet[i];
        }
    }
    cout<<t<<endl;
    return 0;
}
