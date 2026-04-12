#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;
const int INF=1<<30;

int main(){
    int H,W;
    cin >> H >> W;
    char a[H][W];
    bool t[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> a[i][j];
            t[i][j]=true;
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int k=0;k<W;k++){
                if(a[i][k]=='#') break;
                if(k==W-1) t[i][j]=false;
            }
            for(int k=0;k<H;k++){
                if(a[k][j]=='#') break;
                if(k==H-1) t[i][j]=false;
            }
        }
    }
    for(int i=0;i<H;i++){
        bool c=false;
        for(int j=0;j<W;j++){
            if(t[i][j]){
                cout << a[i][j];
                c=true;
            }
            if(j==W-1&&c) cout << "\n";
        }
    }
    return 0;
}
