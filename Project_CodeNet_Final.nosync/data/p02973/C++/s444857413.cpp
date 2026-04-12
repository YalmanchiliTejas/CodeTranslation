#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>
typedef long long ll;

using namespace std;

int b[500000];
//int ans[500000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(100);
 //   freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> b[i];
    }
    multiset <int> s;
    int ans=1;
    s.insert(b[0]);
    for(int i=1;i<n;i++){
        auto it =s.lower_bound(b[i]);
        if(it == s.begin()){
            ans++;
            s.insert(b[i]);
        }
        else{
            it--;
            s.erase(it);
            s.insert(b[i]);
        }
    }
    cout<<ans;
    return 0;
}
