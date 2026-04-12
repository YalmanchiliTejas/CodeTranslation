#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    int N;
    cin >> N;
    vec<int> cnt(26,100);
    for(int i=0;i<N;i++){
        string S;
        cin >> S;
        vec<int> v(26);
        for(auto& c:S) v[c-'a']++;
        for(int j=0;j<26;j++) cnt[j] = min(cnt[j],v[j]);
    }
    string ans = "";
    for(int i=0;i<26;i++){
        char c = 'a'+i;
        for(int j=0;j<cnt[i];j++) ans += c;
    }
    cout << ans << "\n";
}