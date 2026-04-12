#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>
#include <limits.h>

using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBAG = false;

int main(){

    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    vector< vector<ll> > v(n);
    for(int i = 0; i < n; i++){
        v[i].resize(26);
        for(int j = 0; j < s[i].size(); j++ ){
            char c =  s[i][j] - 'a';
            v[i][c] ++;
        }
    }


    for(int i = 0; i < 26; i++){
        ll minCnt = 100;
        for(int j = 0; j < n; j++){
            minCnt = min( v[j][i], minCnt  );
        }
        for(int j = 0; j < minCnt; j++){
            cout << (char)(i + 'a') ;
        }
    }
    cout << endl;

}