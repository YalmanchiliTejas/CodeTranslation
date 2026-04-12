#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

int gcd(int a, int b){
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}

bool is753(int n){
    string s = to_string(n);
    if ((int)s.size() < 3)  {
        return false;
    }

    vi a(3,0);
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '3') {
            a[0]++;
        }else if (s[i] == '5'){
            a[1]++;
        }else if (s[i] == '7'){
            a[2]++;
        }else{
            return false;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (a[i] == 0) {
            return false;
        }
    }
    return true;
}

int N;
int dfs(string s){
    if (stol(s) > N) {
        return 0;
    }

    int ret = is753(stoi(s)) ? 1 : 0;
    string cand = "753";
    for (int i = 0; i < 3; i++) {
        string stmp = {cand[i]};
        ret += dfs(s + stmp);
    }
    return ret;
}


void solve(){
    int n;
    cin >> n;

    if (n == 7 || n == 5 || n == 3) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return;
}

int main(int argc, char const* argv[])
{
    solve();
    return 0;
}

