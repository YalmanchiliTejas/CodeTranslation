#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a,mx=0,cnt = 0;
    for(int i = 0;i < n;++i){
        scanf("%d",&a);
        if(a >= mx) cnt++;
        mx = max(a,mx);
    }
    cout << cnt << endl;
    return 0;
}
