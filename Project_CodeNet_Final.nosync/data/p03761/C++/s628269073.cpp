#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define INF 1e9


string comon_string(string s1, string s2){
    map<char, int> map1, map2;
    for(auto i : s1){
        map1[i]++;
    }
    for(auto i : s2){
        map2[i]++;
    }
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string s;
    for(auto c : alphabet){
        rep(i,min(map1[c], map2[c])){
            s += c;
            
        }
    }
    return s;
}


int main(){
   
    
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n)  cin >> s[i];
    string ans = s[0];
   
    rep(i,n){
        ans = comon_string(s[i], ans);
   
        
    }
    cout << ans << endl;
     
     
}
