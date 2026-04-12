#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <numeric>
#include <map>
#include <set>
using namespace std;

char m2[101][101], m3[101][101];
void f(int r, int c) {
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            cout<<m3[i][j];
        }
        cout<<'\n';
    }
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int r, c, r1=0, c1=0;
    cin>>r>>c;
    for (int i=0; i<r; ++i) {
        vector<char> t(c);
        bool ok=1;
        for (int j=0; j<c; ++j) {
            char ch;
            cin>>ch;
            t[j]=ch;
            if (ch=='#') {
                ok=0;
            }
        }
        if (!ok) {
            for (int j=0; j<c; ++j) {
                m2[r1][j]=t[j];
            }
            ++r1;
        }
    }
    for (int j=0; j<c; ++j) {
        vector<char> t(r1);
        bool ok=1;
        for (int i=0; i<r1; ++i) {
            t[i]=m2[i][j];
            if (t[i]=='#') {
                ok=0;
            }
        }
        if (!ok) {
            for (int i=0; i<r1; ++i) {
                m3[i][c1]=t[i];
            }
            ++c1;
        }
    }
    f(r1, c1);
    return 0;
}