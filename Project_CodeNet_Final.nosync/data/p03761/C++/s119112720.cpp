#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<map<char, int> > m(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < s[i].size(); j++){
            m[i][s[i][j]]++;
        }
    }

    vector<pair<char, int> > m2;
    for(char c = 'a'; c <= 'z'; c++){
        bool flag = true;
        int cnt = 50;
        for(int i = 0; i < m.size(); i++){
            if(m[i][c]){
                cnt = min(cnt, m[i][c]);
            }else{
                flag = false;
                break;
            }
        }
        if(flag) m2.push_back(make_pair(c, cnt));
    }

    sort(all(m2));
    for(int i = 0; i < m2.size(); i++){
        for(int j = 0; j < m2[i].second; j++){
            cout << m2[i].first;
        }
    }
    cout << endl;
}
