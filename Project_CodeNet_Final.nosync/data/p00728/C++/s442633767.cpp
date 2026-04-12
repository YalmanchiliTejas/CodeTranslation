#include "bits/stdc++.h"

#define sai(j,n) for(sei j=0;j<sei(n);++j)
#define hsai(j,n) for(sei j=sei(n)-1;j>=0;--j)
#define kan(j,m,n) for(sei j=m;j<sei(n);++j)
#define hkan(j,m,n) for(sei j=sei(n)-1;j>=sei(m);--j)
#define zen(v) (v).begin(),(v).end()
#define yu(v) v.erase(unique(zen(v)), v.end());
#define syutu(v) si(a, (v).size()) {cout << v[a];if(a != v.size()-1)cout << " ";else cout << endl;}
#define mug 10000000111;
#define yo 10000000711;
#define kyo 1e-9;

const int dx[8] = {1,1,0,-1,-1,-1,0,1};
const int dy[8] = {0,1,1,1,0,-1,-1,-1};

using namespace std;
typedef long long sei;
typedef long double syo;
typedef vector<sei> vs;
typedef vector<syo> vy;
typedef vector<vs> vvs;
typedef vector<vy> vvy;
typedef pair<sei, sei> ks;
sei max(sei a, int b) {return max(a, sei(b));}
sei max(int a, sei b) {return max(sei(a), b);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sei n;
    while(cin >> n,n){
        vector<sei> s(n);
        sai(j,n){
            cin >> s[j];
        }

        sort(s.begin(),s.end());
        sei m = 0;
        kan(j,1,n-1){
            m += s[j];
        }
        m /= n-2;
        cout << m << endl;
    }
    return 0;
}
