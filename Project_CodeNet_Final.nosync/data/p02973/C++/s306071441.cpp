#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long a[n];

    for(long long i = 0; i < n; i++) cin >> a[i];

    multiset<long long> T;

    for(long long i = 0; i < n; i++){
        auto it = T.lower_bound(a[i]);

        if(it != T.begin()) T.erase(--it);
        T.insert(a[i]);
    }

    cout << T.size() << endl;
    return 0;
}