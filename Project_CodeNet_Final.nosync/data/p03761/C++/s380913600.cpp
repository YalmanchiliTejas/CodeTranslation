#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    int n; sc(n)
    vector<map<char, int>> mp(n);
    vector<string> vs;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        vs.push_back(s);
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j < vs[i].size(); j++){
            ++mp[i][vs[i][j]];
        }
    }
    bool check;
    sort(vs[0].begin(), vs[0].end());
    for (int i = 0; i < vs[0].size(); i++){
        check = true;
        for (int j = 1; j < n; j++){
            if (mp[j].find(vs[0][i]) != mp[j].end() && mp[j][vs[0][i]] != 0){
                mp[j][vs[0][i]] -= 1;
            } else check = false;
        }
        if (check) cout << vs[0][i];
    }
    cout << endl;
    return 0;
}