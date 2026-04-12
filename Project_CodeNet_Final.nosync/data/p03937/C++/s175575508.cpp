#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h,w,cnt=0;
    cin >> h >> w;
    char a[10][10];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
            if(a[i][j]=='#') cnt++;
        }
    }
    if(cnt==h+w-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}