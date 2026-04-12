#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()
template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    int n;
    cin >> n;
    vector<int> ans(26, INT_MAX);
    while(n--){
        vector<int> h(26);
        string s;
        cin >> s;
        for(int i=0; i<(int)s.length(); ++i)
            h[s[i]-'a']++;
        
        for(int i=0; i<26; ++i){
            ans[i] = min(ans[i], h[i]);
        }
    }

    for(int i=0; i<26; ++i){
        if(ans[i]){
            cout << string(ans[i], 'a'+i);
        }
    }
}