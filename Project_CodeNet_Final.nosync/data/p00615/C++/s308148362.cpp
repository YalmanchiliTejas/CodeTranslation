#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define pb(a) push_back(a)
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << "debug " << x << endl;
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n||m){
        vector<int> v;
        v.pb(0);
        rep(i,n + m){
            int inp;
            cin >> inp;
            v.pb(inp);
        }
        sort(all(v));
        int longer = 0;
        rep(i,v.size() - 1){
            longer = max(longer, v[i + 1] - v[i]);
        }
        cout << longer << endl;
    }
}