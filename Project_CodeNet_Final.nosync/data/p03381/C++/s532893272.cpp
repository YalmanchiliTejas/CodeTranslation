#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multiset<int> ms;
    vector<int> x;
    int n;
    cin >> n;
    for (int i=0; i < n; i++){
        int a;
        cin >> a;
        x.push_back(a);
        ms.insert(a);
    }
    multiset<int>::iterator it = ms.begin();
    int nz = (n+1) / 2 - 1;
    while (nz > 0){
        nz--;
        it++;
    }
    for (int i=0; i < n; i++){
        int el = x[i];
        if (el > *it) cout << *it << endl;
        else{
            it++;
            cout << *it << endl;
            it--;
        }
    }
    return 0;
}



