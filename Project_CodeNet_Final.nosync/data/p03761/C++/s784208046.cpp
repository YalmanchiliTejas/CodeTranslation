#include<bits/stdc++.h>
constexpr long long INFL = 1LL << 60;
constexpr int INF = 1 << 30;

using namespace std;

using ll = long long;
using P = tuple<int, int>;
using iarr = valarray<int>;

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    int a[26];
    for(int i = 0; i < 26; ++i) a[i] = INF;
    for(auto itr = v.begin(); itr != v.end(); ++itr){
        for(char c = 'a'; c <= 'z'; ++c){
            a[c-'a'] = min(static_cast<int>(count(itr->begin(), itr->end(), c)), a[c-'a']);
        }
    }
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < a[i]; ++j){
            cout << static_cast<char>('a' + i);
        }
    }
    cout << endl;


    return 0;
}