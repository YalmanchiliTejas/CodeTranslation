#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<(int)(b);(i)++)
#define RREP(i,a,b) for(int (i)=(a);(i)>=(int)(b);(i)--)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;



int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    REP(i,0,n){
        cin >> s[i];
    }

    string ans = "";
    for (char c = 'a'; c <= 'z'; c++){
        int small = 100;
        REP(i,0,n){
            int cnt = 0;
            REP(j,0,s[i].size()){
                if (s[i][j] == c) cnt++;
            }
            small = min(small, cnt);
        }
        REP(i,0,small){
            ans += c;
        }
    }

    cout << ans << endl;
    
    return 0;
}