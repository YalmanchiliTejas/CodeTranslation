#include <iostream>
using namespace std;
char c[105][105];
bool row[105];
bool col[105];
int main() {
    int h,w;
    cin >> h >> w;
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) cin >> c[i][j];
    }
    for (int i=1;i<=h;i++) {
        int cnt=0;
        for (int j=1;j<=w;j++) {
            if (c[i][j]=='.') cnt++;
        }
        if (cnt==w) row[i] = 1;
    }
    for (int i=1;i<=w;i++) {
        int cnt = 0;
        for (int j=1;j<=h;j++) {
            if (c[j][i]=='.') cnt++;
        }
        if (cnt==h) col[i] = 1;
    }
    for (int i=1;i<=h;i++) {
        bool o = false;
        for (int j=1;j<=w;j++) {
            if (row[i]||col[j]) continue;
            else {cout << c[i][j];o = true;}
        }
        if (o) cout << endl;
    }
    return 0;
}