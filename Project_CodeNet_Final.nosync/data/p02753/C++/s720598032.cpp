#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    if (s[0] == s[1]&&s[0] == s[2]&&s[2] == s[1])
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

}
