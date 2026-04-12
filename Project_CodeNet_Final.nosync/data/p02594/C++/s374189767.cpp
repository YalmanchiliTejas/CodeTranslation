#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

// ----- Tools ----- //
template <typename Key, typename Value, typename Arg>
bool containsKey(const unordered_map<Key, Value>& m, const Arg& value) {return m.find(value) != m.end();}
template <typename Key, typename Value, typename Arg>
bool containsKey_tm(const map<Key, Value>& m, const Arg& value) {return m.find(value) != m.end();}
bool startsWith(string str, string tar) {return (str.rfind(tar, 0) == 0);}
bool contains(string str, string tar) {return (str.find(tar) != std::string::npos);}
vector<string> split(string str, char ch) {vector<string> res; stringstream ss(str); string s; while (getline(ss, s, ch)) res.push_back(s); return res; }
char toLower(char& ch) {if ('A' <= ch && ch <= 'Z') return ch - 'A' + 'a'; else return ch;}
char toUpper(char& ch) {if ('a' <= ch && ch <= 'z') return ch - 'a' + 'A'; else return ch;}

// -------- Main Code -------- //

// --------------- //

void runcase() {
    int t;
    cin >> t;
    if (t >= 30) {
        cout << "Yes\n"; 
    } else {
        cout << "No\n";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while (t-- > 0)
        runcase();

    return 0;
}
