#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int MOD = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;

int main()
{
    cin >> H >> W;

    vector<vector<char>> arr(H,vector<char>(W));
    vector<vector<char>> brr(W,vector<char>(H));
    vector<bool> Hrr(200);
    vector<bool> Wrr(200);
    char ccc;
    for (int i = 0; i < H; i++) rep(j,W) 
    {
        cin >> ccc;
        arr.at(i).at(j) = ccc;
        brr.at(j).at(i) = ccc;
    }

    rep(i,H)
    {
        if(count(all(arr[i]),'#')==0)Hrr[i]=true;
    }
    rep(i,W)if(count(all(brr[i]),'#')==0)Wrr[i]=true;

    rep(i,H)
    {
        if(Hrr[i])continue;
    rep(j,W)
    {
        if(Wrr[j])continue;
        cout << arr[i][j];
    }
    cout << endl;
    }
    return 0;
}