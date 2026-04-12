#include<bits/stdc++.h>
using namespace std;

bool cnt[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    for (int i=0; i<n; i++) {
        string s;
        cin>>s;

        for (int j=0; j<m; j++)
            if (s[j] == '#') {
                if (cnt[i+j]) {
                    cout<<"Impossible"<<endl;
                    return 0;
                }
                cnt[i+j] = 1;
            }
    }
    cout<<"Possible"<<endl;
}
