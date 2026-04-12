#include <bits/stdc++.h>
using namespace std;
int n,m,a[101][101],row[101],col[101];
string str;
int main() {
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>str;
        for (int j=0; j<m; j++) a[i][j]=(str[j]=='.');
    }
    for (int i=0; i<n; i++) {
        int x=0;
        for (int j=0; j<m; j++) {
            if (a[i][j]==0) x=1;
        }
        if (!x) row[i]=1;
    }
    for (int i=0; i<m; i++) {
        int x=0;
        for (int j=0; j<n; j++) {
            if (a[j][i]==0) x=1;
        }
        if (!x) col[i]=1;
    }
    for (int i=0; i<n; i++) {
        if (row[i]) continue;
        for (int j=0; j<m; j++) {
            if (col[j]) continue;
            if (a[i][j]) cout<<'.';
            else cout<<'#';
        }
        cout<<'\n';
    }
}