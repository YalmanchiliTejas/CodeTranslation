#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007LL;
const int INF = LLONG_MAX;

char M(char x, char y){

    if(x == 'T' && y == 'F') return 'F';
    else return 'T';

}

signed main(){
    
    int n; cin >> n;
    vector<char> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    char c = p[0];
    for(int i = 1; i < n; i++){
        c = M(c, p[i]);
    }

    cout << c << endl;

    return 0;
}
