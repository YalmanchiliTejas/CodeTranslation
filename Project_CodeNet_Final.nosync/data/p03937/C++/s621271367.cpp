#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define lg length()
#define pb push_back
ifstream in("file.in");
ofstream out("file.out");
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005

int n,m;

char a[10][10],t[10][10];

int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            t[i][j]='.';
        }
    }
    int x=1,y=1; t[x][y]='#';
    while(x!=n || y!=m){
        if(x<n && a[x+1][y]=='#') x++;
        else if(y<m && a[x][y+1]=='#') y++;
        else{
            cout << "Impossible";
            return 0;
        }
        //cout << x << ' ' << y << '\n';
        t[x][y]='#';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!=t[i][j]){
                cout << "Impossible";
                return 0;
            }
        }
    }
    cout << "Possible";
}
