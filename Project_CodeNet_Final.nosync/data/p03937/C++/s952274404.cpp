#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> A(H),A_(H+1);
    rep(i,H) {
        cin >> A[i];
        A_[i] = A[i] + '.';
    }
    rep(i,W+1) A_[H][i] = '.';
    int x=0,y=0;
    vector<string> ans;
    ans = A;
    rep(i,H){
        rep(j,W){
            ans[i][j]='.';
        }
    }
    ans[0][0]='#';
    while(1){
        if(A_[y][x+1]=='#'&&A_[y+1][x]=='#'){
            cout << "Impossible" << endl;
            return 0;
        }else{
            if(A_[y][x+1]=='#'){
                x++;
            }else if(A_[y+1][x]=='#'){
                y++;
            }else{
                cout << "Impossible" << endl;
                return 0;
            }
        }
        ans[y][x] = '#';
        if(x==W-1&&y==H-1){
            break;
        }
    }
    bool f = true;
    rep(i,H){
        if(ans[i]!=A[i]) f= false;
    }
    if(f) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}