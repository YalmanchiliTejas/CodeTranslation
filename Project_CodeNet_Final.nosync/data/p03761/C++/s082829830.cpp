#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#define REP(i, n) for(int i=0; i<n; i++)
#define REPR(i, n) for(int i=n; i>=0; i--)
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define INF 10000000000;
using namespace std;
typedef unsigned long ul;
typedef long long ll;
typedef pair<ll, ll> p;

int main(void) {
    ll n, i, j;
    string s, t;
    cin >> n;
    ll ans[26];
    
    for(i=0; i<26; i++)
        ans[i]=INF;
    
    for(i=0; i<n; i++) {
        ll cnt[26]={0};
        cin >> s;
        
        for(j=0; j<(ll)s.size(); j++) {
            cnt[s[j]-'a']++;
        }
        
        for(j=0; j<26; j++) {
            ans[j]=min(ans[j], cnt[j]);
        }
    }
    
    for(i=0; i<26; i++) {
        for(j=0; j<ans[i]; j++)
            t+=(char)(i+'a');
    }
    cout << t << endl;
    
}