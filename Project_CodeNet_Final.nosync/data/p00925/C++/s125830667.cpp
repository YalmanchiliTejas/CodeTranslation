#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<ll, ll>;
using namespace std;

template<class t> void vin(vector<t>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int get_m(string s) {
    if (s.size() == 1) return s[0]-'0';
    vector<string> v;
    rep(i, s.size()) {
        if (s[i] != '*') {
            string tmp = "";
            tmp += s[i];
            v.push_back(tmp);
        }
        else {
            string last = v[v.size()-1];
            v.pop_back();
            int num1 = stoi(last);
            int num2 = (s[i+1]-'0');
            int tmp = num1*num2;
            v.push_back(to_string(tmp));
            i++;
        }
    }
    if (v.size() == 1) {
        return stoi(v[0]);
    }
    int ret = 0;
    for (int i=1; i<v.size(); i+=2) {
        if (i == 1) {
            ret += stoi(v[i-1])+stoi(v[i+1]);
        }
        else {
            ret += stoi(v[i+1]);
        }
    }
    return ret;
}

int get_l(string s) {
    if (s.size() == 1) return s[0]-'0';
    int ret = -1;
    for (int i=1; i<s.size(); i+=2) {
        int num2 = s[i+1]-'0';
        if (i == 1) {
            int num1 = s[i-1]-'0';
            if (s[i] == '+') ret = num1 + num2;
            else ret = num1 * num2;
        }
        else {
            if (s[i] == '+') ret += num2;
            else ret *= num2;
        }
    }
    return ret;
}

int main() {
    string s;
    cin >> s;
    int ans;
    cin >> ans;
    int m = get_m(s);
    int l = get_l(s);
    string ret = "";
    if (m == ans) {
        if (l == ans) {
            ret = "U";
        }
        else {
            ret = "M";
        }
    }
    else if (l == ans) {
        ret = "L";
    }
    else {
        ret = "I";
    }
    cout << ret << endl;
}

