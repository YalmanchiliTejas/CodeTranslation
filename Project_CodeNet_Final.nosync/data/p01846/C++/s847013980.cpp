#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef pair<ll,ll> P;

void print(const vector<string> &ban) {
    int h = ban.size();
    rep(i,h) {
        cout << ban[i] << endl;
    }
}

void encode(const string &s, vector<string> &ban) {
    int n = s.length();
    int h = 1;
    rep(i,n) if (s[i] == '/') ++h;
    ban.resize(h);
    int nowh = 0;
    rep(i,n) {
        if (s[i] == '/') {
            nowh++;
            continue;
        }
        if (s[i] == 'b') {
            ban[nowh].push_back('b');
        }
        else {
            int blank = (int)(s[i]-'0');
            rep(i,blank) ban[nowh].push_back('.');
        }
    }
}

void move_ball(int a, int b, int c, int d, vector<string> &ban) {
    ban[a][b] = '.';
    ban[c][d] = 'b';
    return;
}

string decode(const vector<string> &ban) {
    int h = ban.size();
    string ret;
    rep(i,h) {
        int blank = 0;
        rep(j,ban[i].size()) {
            if (ban[i][j] == '.') blank++;
            else {
                if (blank > 0) {
                    ret.push_back((char)(blank+'0'));
                    blank = 0;
                }
                ret.push_back(ban[i][j]);
            }
        }
        if (blank > 0) ret.push_back((char)(blank+'0'));
        ret.push_back('/');
    }
    ret.pop_back();
    return ret;
}

int main() {
    while (true) {
        string s;
        cin >> s;
        if (s == "#") break;
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        --a,--b,--c,--d;
        vector<string> ban;

        encode(s,ban);
        // print(ban);
        move_ball(a,b,c,d,ban);
        // print(ban);
        string ans = decode(ban);
        cout << ans << endl;
    }
}
