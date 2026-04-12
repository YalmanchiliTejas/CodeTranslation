#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
bool x[maxn],y[maxn];
char maz[maxn][maxn];

int n,m;
int main(){
    cin>>n>>m;
    for (int i=0;i<n;i++) scanf("%s",maz[i]);

    for (int i=0;i<n;i++){
        bool flag = true;
        for (int j=0;j<m;j++) if (maz[i][j] == '#') {flag = false;break;}
        x[i] = flag;
    }
    for (int j=0;j<m;j++){
        bool flag = true;
        for (int i=0;i<n;i++) if (maz[i][j] == '#') {flag = false;break;}
        y[j] = flag;
    }
    for (int i=0;i<n;i++) if (!x[i]){
        for (int j=0;j<m;j++) if (!y[j]) cout<<maz[i][j];
        cout<<endl;
    }
    return 0;
}
