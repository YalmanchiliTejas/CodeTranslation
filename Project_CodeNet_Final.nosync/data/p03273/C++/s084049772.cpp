#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    vector<string> a1;
    for (int i=0; i<h; i++) cin >> a[i];
    for (int i=0; i<h; i++) {
        bool flag=0;
        for (int j=0; j<w; j++) {
            if (a[i][j]=='#') flag=1;
        }
        if (flag) a1.push_back(a[i]);
    }
    vector<int> r;
    for (int j=0; j<w; j++) {
        bool flag=1;
        for (int i=0; i<a1.size(); i++) {
            if (a1[i][j]=='#') flag=0;
        }
        if (flag) r.push_back(j);
    }
    if (r.empty()) {
        for (int i=0; i<a1.size(); i++) cout << a1[i] << endl;
    } else {
        for (int i=0; i<a1.size(); i++) {
            auto itr=r.begin();
            for (int j=0; j<w; j++) {
                if (j!=*itr) cout << a1[i][j];
                else itr++;
            }
            cout << endl;
        }
    }
}