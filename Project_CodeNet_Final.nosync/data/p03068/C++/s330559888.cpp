#include <bits/stdc++.h>
#include <cstdlib>
#define ll long long
#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)
#define MX 100010
using namespace std;

int n,k;
string s;
string ans;
char t;
int main(){
        cin >> n >> s >> k;
        ans = s;
        t = ans[k-1];
        FOR(i,0,n){
                if(s[i] != t) ans.replace(i,1,"*");
        }
        cout << ans << endl;

        return 0;
}
