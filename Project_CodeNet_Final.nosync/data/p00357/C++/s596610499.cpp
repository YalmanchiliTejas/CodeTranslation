#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    scanf("%d", &n);
    vector<int> vec(n);
    rep(i,n) scanf("%d", &vec.at(i));
    bool OK[2];
    rep(j,2) {
        int i=0, m=1;
        OK[j] = false;
        while (i<m) {
            if (i == n-1) {OK[j] = true; break;}
            m = max(m, i+1+vec.at(i)/10);
            i++;
        }
        reverse(all(vec));
    }
    if (OK[0] && OK[1]) printf("yes\n");
    else printf("no\n");
}
