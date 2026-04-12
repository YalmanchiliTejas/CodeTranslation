#include<bits/stdc++.h>
using namespace std;
#define int long long

map<int,int>col,row;
char m[105][105];

signed main(){
    
    int r,c;
    cin >> r >> c;

    for(int i = 0;i<r;i++){
        int cr = 0;
        for(int j = 0;j<c;j++){
            cin >> m[i][j];
            if(m[i][j]=='.')cr++;
        }
        if(cr==c)row[i]=1;
    }

    for(int j = 0;j<c;j++){
        int cc = 0;
        for(int i = 0;i<r;i++){
            if(m[i][j]=='.')cc++;
        }
        if(cc==r)col[j]=1;
    }

    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(!row[i] && !col[j])cout << m[i][j];
        }
        if(!row[i])cout << endl;
    }
    return 0;
}
