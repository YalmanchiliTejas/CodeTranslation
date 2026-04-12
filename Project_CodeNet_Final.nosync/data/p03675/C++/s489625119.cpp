#define MOD 1000000007;
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll long long

#include <bits/stdc++.h>

using namespace std;
const int N = 2e1 + 5;

int main() {

    ll n;
    cin >> n;
    vector<int> vec;
    deque<int> ans;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(i%2)
            ans.push_front(x);
        else ans.push_back(x);
    }
    if(n%2==0)
        reverse(ans.begin(),ans.end());
    for(auto v: ans)
    cout<<v<< " ";


}