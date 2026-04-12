#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<string>A(H);
    for(int i=0; i<H; i++) cin >> A[i];

    string ans = "Possible";
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++)
        {
            int downright = 0;
            int upleft = 0;
            if(A[i][j] != '#') continue;
            if(i+1!=H && A[i+1][j] == '#') downright++;
            if(j+1!=W && A[i][j+1] == '#') downright++;
            if(i-1!=-1 && A[i-1][j] == '#') upleft++;
            if(j-1!=-1 && A[i][j-1] == '#') upleft++;
            if(!(i==H-1 && j==W-1) && (downright == 0 || downright == 2)) ans = "Impossible";
            if(!(i==0 && j==0) && (upleft == 0 || upleft == 2)) ans = "Impossible";
        }
    }
    cout << ans << endl;

    return 0;
}
