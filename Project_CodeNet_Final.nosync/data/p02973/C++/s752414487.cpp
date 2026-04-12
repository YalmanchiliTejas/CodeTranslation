#include <bits/stdc++.h>

using namespace std;

int n;

void solve(){
    int i,j;
    string str;
    cin >> n;
    multiset<int> s;
    s.insert(-1);
    for(i = 0;i < n;i++){
        cin >> j;
        multiset<int>::iterator it = s.upper_bound(j-1);
        if(it == s.begin()){
            s.insert(j);
            continue;
        }
        else{
            s.erase(--it);
            s.insert(j);
        }
    }
    long long ans = s.size();
    cout << ans << endl;
}

int main(){
    solve();
}
