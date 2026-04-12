#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

string s[55];
int cnt[55][26];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
        for(int j=0;j<s[i].length();j++){
            cnt[i][s[i][j]-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        int mn = 1e9;
        for(int j=0;j<n;j++){
            mn = min(mn, cnt[j][i]);
        }
        for(int j=0;j<mn;j++) printf("%c", i+'a');
    }
}