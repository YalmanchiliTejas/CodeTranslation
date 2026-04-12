#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<char,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int h, w;
    cin >> h >> w;

    int cnt = 0;
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;

            if(c == '#'){
                cnt++;
            }
        }
    }

    if(cnt == h + w - 1){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }

    return 0;
}