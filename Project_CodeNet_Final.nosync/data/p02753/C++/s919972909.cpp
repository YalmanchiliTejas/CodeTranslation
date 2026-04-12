/**
 *  author: mahfuzz
 *  created: 22.03.2020
**/
 
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << ':' << x << "\n";
//~ const double pi = 2*acos(0.0);
//~ const long long mod = 1e9+7;
//~ const int max_n = 1e6+5;
typedef long long ll;

int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    string s; cin >> s;
    
    for(int i = 1; s[i]; i++){
        if(s[i] != s[i-1]){
            cout << "Yes\n";
            return 0;
        }
    }
    
    cout << "No\n"; 
        
    return 0;
}
