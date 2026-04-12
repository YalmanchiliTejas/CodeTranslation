#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    deque<int> dq;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if((i+n)%2==1) dq.push_front(a);
        else dq.push_back(a);
    }

    for(auto x : dq) cout << x << " ";
    cout << endl;

    return 0;
}