//#include <bits/stdc++.h>
#include<set>
#include<iostream>
using namespace std;

int main() {
    multiset<int> set;

    int n; cin >> n;

    while(n--){
        int a; cin >> a;
        if(set.size() == 0) {
            set.insert(a);
            continue;
        }
        
        auto itr = set.lower_bound(a);
        if(itr != set.begin()){
            --itr;
            set.erase(itr);
        }
        set.insert(a);
    }

    cout << set.size() << endl;
}
