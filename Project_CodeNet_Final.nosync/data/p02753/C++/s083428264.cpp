//Let's play :)
#include<bits/stdc++.h>
using namespace std;

#define tarzan ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long 

int rr[] = {0, 1, 1, 1, 0, -1, -1, -1};
int cc[] = {1, 1, 0, -1, -1, -1, 0, 1};

const int mod = 1e9 + 7;
const int N = 300050;

signed main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    tarzan;
    int test = 1;
    //cin >> test;
    while(test--) {
        string s;
        cin >> s;
        if(s[0] == s[1] && s[1] == s[2]) {
            cout << "No";
        }
        else cout << "Yes";
    }
    return 0;
}