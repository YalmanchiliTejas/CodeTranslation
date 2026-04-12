#include <bits/stdc++.h>
using namespace std;

#define int long long
#define DEBUG(x) cerr <<#x<<":"<<x<<endl;
#define DEBUG2(x, y) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define DEBUG3(x, y, z) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl;
#define DEBUGVC(x) cerr <<#x<<": "; for(auto a:x) cerr << a <<" "; cerr << endl;
#define DEBUGMP(x) cerr <<#x<<":"<<endl; for(auto a:x) cerr << a.first <<" "<< a.second << endl;
#define MAX_N (1000006)
#define INF (1LL << 60)
const int MOD = (int)1e9+7;


signed main() {
    string t = "yuiophjklnm";
    while(1) {
        string s;
        cin >> s;
        if (s == "#") return 0;
        bool F = false;
        int ans=0;
        for(int i=0; i<s.length(); i++){
            bool f = false;
            for(int j=0; j<t.length(); j++){
                if (s[i]==t[j]){
                    f = true;
                }
            }
            if(i==0) {
                if(f) F=true;
                else F=false;
                continue;
            }
            if(F != f) ans++;
            F = f;
        }
        cout << ans << endl;
    }
}
