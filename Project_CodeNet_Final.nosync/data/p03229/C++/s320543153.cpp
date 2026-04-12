#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    multiset<int> num;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        num.insert(a);
    }

    long long int small  = *num.begin();
    long long int large = *prev(num.end());
    num.erase(num.begin());
    num.erase(prev(num.end()));

    long long int ans = large - small;

    while(num.size() >= 2){
        ans += *prev(num.end()) - small;
        ans += large - *num.begin();

        small = *num.begin();
        large = *prev(num.end());

        num.erase(prev(num.end()));
        num.erase(num.begin());
    }
    if(num.empty() == false){
        ans += max(large - *num.begin(), *num.begin() - small);
    }
    cout << ans << endl;
    return 0;
}