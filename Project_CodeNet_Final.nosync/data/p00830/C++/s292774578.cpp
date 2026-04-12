#include <bits/stdc++.h>

using namespace std;

//#define LOG(...) fprintf(stderr, __VA_ARGS__)
#define LOG(...)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define RFOR(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); --i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define RREP(i, n) for (int i = (int)(n - 1); i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SZ(a) ((int)(a).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define SQ(x) ((x) * (x))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set<string> dirs, paths;

string join_path(vs& path) {
    if (SZ(path) == 0) return "/";
    stringstream ss;
    REP(i, SZ(path)) {
        ss << "/" << path[i];
    }
    return ss.str();
}

bool traverse(const string& s, string& t) {
    vs path;
    size_t i = 0, j = 0;
//    LOG("== %s\n", s.c_str());
    while ((i = s.find('/', i+1)) != string::npos) {
        string dir = s.substr(j+1, i-1-j);
//        LOG("%s\n", dir.c_str());
        if (dir == ".") {
        } else if (dir == "..") {
            if (SZ(path) > 0) path.pop_back();
        } else {
            path.push_back(dir);
        }
        if (!EXIST(dirs, join_path(path))) {
            LOG("--> no %s\n", join_path(path).c_str());
            return false;
        }
        j = i;
    }
    if (j+1 < SZ(s)) {
        string file = s.substr(j+1, SZ(s));
        if (file == ".") {
        } else if (file == "..") {
            if (SZ(path) > 0) path.pop_back();
        } else {
            path.push_back(file);
        }
    }
    if (EXIST(paths, join_path(path))) {
        LOG("--> ok %s\n", join_path(path).c_str());
        t = join_path(path);
        return true;
    }
    path.push_back("index.html");
    if (EXIST(dirs, join_path(path))) {
        LOG("--> no index.html %s\n", join_path(path).c_str());
        return false;
    }
    if (EXIST(paths, join_path(path))) {
        LOG("--> ok index.html %s\n", join_path(path).c_str());
        t = join_path(path);
        return true;
    }
    LOG("--> no failed %s\n", join_path(path).c_str());
    return false;
}

int main() {
    int n, m;
    while (cin >> n >> m, n|m) {
        dirs.clear();
        dirs.insert("/");
        paths.clear();

        REP(_i, n) {
            string s;
            cin >> s;
            paths.insert(s);
            size_t i = 0;
            while ((i = s.find('/', i+1)) != string::npos) {
                string dir = s.substr(0, i);
                dirs.insert(dir);
            }
        }

        REP(i, m) {
            string s1, s2;
            cin >> s1 >> s2;
            string t1, t2;
            if (traverse(s1, t1) && traverse(s2, t2)) {
                if (t1 == t2) {
                    cout << "yes" << endl;
                } else {
                    cout << "no" << endl;
                }
            } else {
                cout << "not found" << endl;
            }
        }
    }
}