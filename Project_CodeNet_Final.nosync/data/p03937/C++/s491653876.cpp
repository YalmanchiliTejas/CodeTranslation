//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[]{0, 1, 0, 1};
int dy[]{1, 0, 1, 0};

signed main()
{
    int h, w;
    cin >> h >> w;
    int cnt = 0;
    for(int i=0; i<h; ++i) {
        string s;
        cin >> s;
        for(int i=0; i<s.size(); ++i)
            if(s[i]=='#') cnt++;
    }
    if(cnt==w+h-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}

