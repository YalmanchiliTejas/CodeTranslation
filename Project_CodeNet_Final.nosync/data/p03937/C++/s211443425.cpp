#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for(int i=0; i<H; i++) cin >> A[i];

    int cnt = 0;
    for(auto s : A) for(auto c : s) if(c=='#') cnt++;
    cout << (cnt == H+W-1 ? "Possible" : "Impossible") << endl;

    return 0;
}
