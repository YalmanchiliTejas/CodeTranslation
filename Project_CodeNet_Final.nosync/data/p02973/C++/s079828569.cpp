#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    deque<int> dq;
    for(int i = 0; i < n; ++i){
        int id = lower_bound(dq.begin(), dq.end(), a[i]) - dq.begin();
        if(id == 0)     dq.push_front(a[i]);
        else            dq[id - 1] = a[i];
    }
    int ans = (int)dq.size();
    cout << ans << endl;
}