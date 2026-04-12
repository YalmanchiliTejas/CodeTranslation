#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define dump(x) cout << "[*] " #x ": " << x << endl
#define debug(x) x
#else
#define dump(x)
#define debug(x)
#endif

string input;
int a, b, c, d;
vector<string> t;

inline string decode_line(const string& in) {
    string ret;
    for (const char& c : in) {
        if (c == 'b') {
            ret.push_back('b');
        } else {
            const int m = c - '0';
            //dump(m);
            //dump(c);
            for (int i = 0; i < m; ++i) {
                //dump(i);
                ret.push_back('.');
            }
        }
    }
    debug(cout << ret << endl);
    return ret;
}

inline vector<string> decode(const string& in) {
    stringstream ss(input);
    string buf;
    vector<string> ret;
    debug(cout << "-- decode --" << endl;);
    while (getline(ss, buf, '/')) {
        ret.push_back(decode_line(buf));
    }
    return ret;
}

inline string encode_line(const string& in) {
    int cnt = 0;
    string ret;
    for (const char& c : in) {
        if (c == '.') {
            cnt++;
        } else {
            if (cnt) {
                ret.push_back('0' + cnt);
                cnt = 0;
            }
            ret.push_back('b');
        }
    }
    if (cnt) {
        ret.push_back('0' + cnt);
    }
    dump(ret);
    return ret;
}

inline string encode(const vector<string>& in) {
    string ret;
    debug(cout << "-- encode --" << endl);
    for (const string& s : in) {
        ret += encode_line(s);
        ret.push_back('/');
    }
    ret.pop_back();
    debug(cout << "-- output --" << endl);
    return ret;
}

int main() {
    while (true) {
        cin >> input;
        if (input[0] == '#') {
            break;
        }
        cin >> a >> b >> c >> d;
        t = decode(input);
        t[a-1][b-1] = '.';
        t[c-1][d-1] = 'b';
        cout << encode(t) << endl;
    }
    return 0;
}

