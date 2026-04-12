#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    string s;
    cin >> s;
    bool flag = true;
    rep(i, s.size() - 1)
    {
        if(s[i]!=s[i+1]){
            flag = false;
        }
    }
    if(flag){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}