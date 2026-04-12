#include <bits/stdc++.h>
using namespace std;

int n, temp;
deque<int> ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if(n==1) {
        cin >> temp;
        cout << temp << '\n';
    } else if(n==2) {
        cin >> temp;
        ans.push_back(temp);
        cin >> temp;
        ans.push_front(temp);
        for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
    } else {
        for(int i=1; i<=n; i++) {
            cin >> temp;
            if(i%2!=0) ans.push_front(temp);
            else ans.push_back(temp);
        }
    }
    if(n>2) {
        if(n%2==0) for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << ' ';
        else for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
    }

    return 0;
}
