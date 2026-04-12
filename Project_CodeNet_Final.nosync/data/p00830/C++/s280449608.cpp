#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)

void enumerate(const string& path, set<string>& dirs) {
    auto p = path.find_last_of('/');
    if (p == string::npos) return;
    string dirname = path.substr(0, p);
    if (!dirs.insert(dirname + '/').second) return;
    enumerate(dirname, dirs);
}

string fix(const string& path, const set<string>& dirs, const set<string>& files) {
    string par = "", sub = path;
    for (; !sub.empty();) {
        if (sub.size() >= 3u and sub.substr(0, 3) == "/..") {
            if (par.empty()) throw "not found";
            auto p = par.find_last_of('/');
            par.erase(par.begin() + p, par.end());
            sub.erase(0, 3);
        }
        else if (sub.size() >= 2u and sub.substr(0, 2) == "/.") {
            sub.erase(0, 2);
        }
        else {
            if (sub == "/") break;
            auto p = sub.substr(1).find_first_of('/');
            if (p == string::npos) { par += sub; break; }
            par += sub.substr(0, p + 1);
            sub.erase(0, p + 1);
        }
        if (sub.empty() and files.count(par)) break;
        if (!dirs.count(par + '/')) throw "not found";
    }
    if (dirs.count(par + '/') and files.count(par + "/index.html")) return par + "/index.html";
    if (!files.count(par)) throw "not found";
    return par;
}

int main() {
    for (int N, M; cin >> N >> M, N | M;) {
        set<string> dirs, files;
        while (N--) {
            string path; cin >> path;
            files.insert(path);
            enumerate(path, dirs);
        }
        while (M--) {
            string path1, path2; cin >> path1 >> path2;
            try { cout << (fix(path1, dirs, files) == fix(path2, dirs, files) ? "yes" : "no") << endl; }
            catch (char const* mes) { cout << mes << endl; }
        }
    }
    return 0;
}