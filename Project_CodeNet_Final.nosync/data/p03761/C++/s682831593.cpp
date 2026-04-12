#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int n;
    cin >> n;
    int alph_min[30] = {0};
    map<char,int> alph[n];
    rep(i,n){
        string s;
        cin >> s;
        rep(j,s.length()){
            alph[i][s[j]]++;
        }
    }
    int cnt;
    for(auto itr = alph[0].begin();itr!=alph[0].end();itr++){
        char key = itr->first;
        cnt = alph[0][key];
        for(int i = 1; i < n; i++){
            
            if(alph[i].find(key)==alph[i].end()) {
                cnt = 0;
                continue;
            }
            cnt = min(cnt,alph[i][key]);
        }
        rep(i,cnt){
            cout << itr->first;
        }
    }
    cout << endl;
    return 0;
}