
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repr(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<(int)(n);i++)
#define INF 999999999

    /*Solve*/
bool rec(int i,int j,char a[10][10]){
    if(a[i][j]=='G')return true;
    if(a[i+1][j]=='#'){
        rec(i+1,j,a);
    }else if(a[i][j+1]=='#'){
        rec(i,j+1,a);
    }else return false;
    return false;
}

int main(){
    int h,w;
    cin >> h >> w;
    char a[10][10];
    memset(a,'.',sizeof(a));
    FOR(i,1,h+1)FOR(j,1,w+1){
        cin >> a[i][j];
    }
    FOR(i,1,h+1)FOR(j,1,w+1){
        if(a[i][j]=='#'){
            if(a[i+1][j]=='#' && a[i+1][j-1]=='#'){
                cout << "Impossible";
                return 0;
            }
            if(a[i-1][j]=='#' && a[i-1][j+1]=='#'){
                cout << "Impossible";
                return 0;
            }
        }
    }
    cout << "Possible";
}