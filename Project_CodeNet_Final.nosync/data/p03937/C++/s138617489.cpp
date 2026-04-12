#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef long long ll;
typedef vector<pii> vpii;
#define reps(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define all(g) (g).begin(),(g).end()
#define pb push_back
const int mod = 1e9 + 7;
#define INF 1<<25
/*
input case
output case
*/

int H, W;
char A[10][10];


bool check_area(int x, int y){
    // x--;
    y++;
    reps(i,y,H) rep(j,x) {
        if (A[j][i] == '#') return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;

    rep(i,H) rep(j,W) {cin >> A[j][i];}

    int flag = 1;

    rep(i,H){
        reps(j,1,W){
            if (A[j][i] == '#'){
                if (check_area(j,i)) {flag = 0;}
            }
        }
    }

    if(flag){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }

}