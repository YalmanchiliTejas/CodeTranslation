#include <bits/stdc++.h>


using namespace std;
using ll= long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;

string f(vector<int> v, bool& valid, string s){
    //cout << v.size() << endl;
    int n = v.size(), last, next;
    for (int i=0; i<n; i++){
        last = (i -1 + n)%n, next = (i + 1 + n)%n;
        if ((s[i] == 'o' and v[i] == 2) || (s[i] == 'x' and v[i] == 1)){
            if (v[last] + v[next] == 3){
                valid = false;
                return "-";
            }
            v[last] = v[next] = max(v[last], v[next]);
        }
        else {
            if (v[last] == v[next]) return "-";
            if (v[last] == 0) v[last] = 3 - v[next];
            else v[next] = 3 - v[last];
        }
    }
    string ans;
    for (int i=0; i<n; i++){
        if (v[i] == 1) ans += 'W';
        else ans+= 'S';
    }
    valid = true;
    return ans;
}

int main (){
    bool valid = false;
    int n;
    string s, ans;
    cin >> n >> s;

    vector<int> v(n, 0);
    v[0] = v[1] = 1;
    ans = f(v, valid, s);
    if (valid){
        cout << ans << endl;
        return 0;
    }

    // v.clear();
    v[0] = v[1] = 2;
    ans = f(v, valid, s);
    if (valid){
        cout << ans << endl;
        return 0;
    }

    // v.clear();
    v[0] = 1,  v[1] = 2;
    ans = f(v, valid, s);
    if (valid){
        cout << ans << endl;
        return 0;
    }

    // v.clear();
    v[0] = 2, v[1] = 1;
    ans = f(v, valid, s);
    if (valid){
        cout << ans << endl;
        return 0;
    }

    cout << "-1" << endl;
    
    
    return 0;
}