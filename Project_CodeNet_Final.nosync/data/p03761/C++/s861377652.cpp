#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 1000000000000000000

int main(void)
{
    int n;
    cin >> n;
    string tmp;
    vector<string> a(n);
    rep(i,n){
        cin >> a[i];
        sort(a[i].begin(), a[i].end());
    }
    int count[n][26] = {0};
    for( int i = 0; i < n; i++){
        for( int j = 0; j < a[i].length(); j++){
            for ( int k = 0; k < 26; k++){
                if( a[i][j] == 'a' + k) count[i][k]++;
            }
        }
    }
    int min[26];
    rep(k,26) min[k] = 1000;
    rep(k,26){
        rep(i,n){
            if( min[k] > count[i][k]){
                min[k] = count[i][k];
            }
        }
    }

    rep(k,26){
        rep(i,min[k]){
            printf("%c", 'a' + k);
        }
    }

    return 0;
}