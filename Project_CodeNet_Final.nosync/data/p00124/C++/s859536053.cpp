#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

int main(){
    int n;
    for(int _ = 0; cin >> n,n; _++){
        pair<int,string> p[21];
        if(_) cout << endl;
        rep(i,n){
            string name;
            int a,b,c;
            cin >> name >> a >> b >> c;
            p[i] = make_pair(a * 3 + c, name);
        }
        sort(p, p + n,
                [](pair<int, string> x, pair<int, string> y) -> bool {
                return ( x.first > y.first );
                } );
        for(auto it:p){
            if(it.second.empty()) break;
            cout << it.second <<',' << it.first << endl;
        }
    }
}