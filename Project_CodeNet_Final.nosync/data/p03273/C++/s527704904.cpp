#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h,w;
    cin>>h>>w;
    string s[h];
    for (int i=0;i<h;i++)
        cin>>s[i];
    set<int> r,c;
    for (int i=0;i<h;i++)
        for (int j=0;j<w;j++)
            if (s[i][j]=='#') {
                r.insert(i);
                c.insert(j);
            }
    for (int i=0;i<h;i++) {
        if (r.count(i)==0)
            continue;
        for (int j=0;j<w;j++) {
            if (c.count(j)==0)
                continue;
            cout<<s[i][j];
        }
        cout<<endl;
    }
    return 0;
}