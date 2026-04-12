#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int N;
    string s;
    cin >> N >> s;
    s.push_back(s[0]);

    string ans;
    ans.clear();
    ans.push_back('S');
    ans.push_back('S');
    for(int i=1; i<=N; i++) {
        if(ans[i] == 'S' && s[i] == 'o' || ans[i] == 'W' && s[i] == 'x') {
            ans.push_back(ans[i-1]);
        } else if(ans[i-1] == 'S') {
            ans.push_back('W');
        } else {
            ans.push_back('S');
        }
    }
    if(ans[0] == ans[N] && ans[1] == ans[N+1]) {
        ans.pop_back();
        ans.pop_back();
        cout << ans << endl;
        return 0;
    }

    ans.clear();
    ans.push_back('S');
    ans.push_back('W');
    for(int i=1; i<=N; i++) {
        if(ans[i] == 'S' && s[i] == 'o' || ans[i] == 'W' && s[i] == 'x') {
            ans.push_back(ans[i-1]);
        } else if(ans[i-1] == 'S') {
            ans.push_back('W');
        } else {
            ans.push_back('S');
        }
    }
    if(ans[0] == ans[N] && ans[1] == ans[N+1]) {
        ans.pop_back();
        ans.pop_back();
        cout << ans << endl;
        return 0;
    }

    ans.clear();
    ans.push_back('W');
    ans.push_back('S');
    for(int i=1; i<=N; i++) {
        if(ans[i] == 'S' && s[i] == 'o' || ans[i] == 'W' && s[i] == 'x') {
            ans.push_back(ans[i-1]);
        } else if(ans[i-1] == 'S') {
            ans.push_back('W');
        } else {
            ans.push_back('S');
        }
    }
    if(ans[0] == ans[N] && ans[1] == ans[N+1]) {
        ans.pop_back();
        ans.pop_back();
        cout << ans << endl;
        return 0;
    }

    ans.clear();
    ans.push_back('W');
    ans.push_back('W');
    for(int i=1; i<=N; i++) {
        if(ans[i] == 'S' && s[i] == 'o' || ans[i] == 'W' && s[i] == 'x') {
            ans.push_back(ans[i-1]);
        } else if(ans[i-1] == 'S') {
            ans.push_back('W');
        } else {
            ans.push_back('S');
        }
    }
    if(ans[0] == ans[N] && ans[1] == ans[N+1]) {
        ans.pop_back();
        ans.pop_back();
        cout << ans << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}
