#include <bits/stdc++.h>
using namespace std;

long long int d[200002];
long long int r[200003];
map<long long int,int> m;

int main() {

    int ans = 0,n;

    cin >> n;

    for(int i=0;i<n;i++){
        scanf(" %lld",&d[i]);
    }

    for(int i=0;i<n;i++){
        r[i+1] = d[i] + r[i];
    }

    for(int i=0;i<n+1;i++){
        if(m[r[i]] == 0 && r[i] != 0){
            m[r[i]] = i;
        }
        else{
            ans = max(ans,i-m[r[i]]);
        }
    }

    cout << ans << endl;

    return 0;
}