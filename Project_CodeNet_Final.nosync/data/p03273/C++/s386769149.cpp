#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int H,W; cin >> H >> W;
    vector<vector<char> > a(H,vector<char>(W));
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) cin >> a[i][j];

    vector<bool> is_height(W,false);
    vector<bool> is_width(H,false);

    //縦のチェック(1列ずつみる)
    for(int j=0;j<W;j++){
        for(int i=0;i<H;i++){
            if(a[i][j] == '#'){
                is_height[j] = true;
                break;
            }
        }
    }

    //横のチェック(1行ずつみる)
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(a[i][j] == '#'){
                is_width[i] = true;
                break;
            }
        }
    }


    for(int i=0;i<H;i++) {
        if(is_width[i] == false)continue;
        for(int j=0;j<W;j++){
            if(is_height[j]==false) ;
            else
                cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
    