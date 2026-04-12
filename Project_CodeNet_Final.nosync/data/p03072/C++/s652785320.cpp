#include <bits/stdc++.h>
using namespace std;

#define ll   long long int
#define rep(i,n)    for(int i=0;i<(int)n;i++)
#define show(s)     cout<<s<<endl

int main() {

    int N;
    cin >> N;

    vector<int> H(N);

    rep(i,N)    cin >> H[i];

    int ans = 0;
    int mx = 0;

    rep(i,N){
        if(H[i] >= mx){
            ans++;
            mx = H[i];
        }
    }
    show(ans);

    return 0;
}
