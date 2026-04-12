#include <bits/stdc++.h>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll,ll> p;
const int MOD = 1000000007;

/*
すぬけ君はこのマス目を圧縮しようとしています。
そのために、白いマスのみからなる行または列が存在する間、次の操作を繰り返し行います。
操作: 白いマスのみからなる行または列をひとつ任意に選び、その行または列を取り除いて空白を詰める。
*/

int main(){
    int H,W;cin>>H>>W;
    vector<vector<char>> a(H,vector<char>(W));
    REP(i,H){
        REP(j,W){
            cin>>a[i][j];
        }
    }

    REP(i,H){//行を操作
        int cnt = 0;
        for(int j=0;j< W;j++){
            if(a[i][j] == '.' or a[i][j] == 'd' ) cnt++;
        }
        if(cnt == W){
            //delete
            for(int j=0;j< W;j++){
            a[i][j] = 'd';
            }
        }
    }

    REP(j,W){//列を操作
        int cnt = 0;
        for(int i=0;i< H;i++){
            if(a[i][j] == '.'  or a[i][j] == 'd') cnt++;
        }
        if(cnt == H){
            //delete
            for(int i=0;i< H;i++){
            a[i][j] = 'd';
            }
        }
    }
    REP(i,H){
        int flag = 0;
        REP(j,W){
            if(a[i][j] != 'd'){
                cout<<a[i][j];
                flag ++;
            }
        }
        cout<<endl;
    }
}