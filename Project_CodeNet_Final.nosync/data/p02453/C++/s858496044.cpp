#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;

    vector<int> a;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int k;
        cin >> k;
        printf("%lld\n",lower_bound(a.begin(), a.end(), k)-a.begin());
    }
    return 0;
}
