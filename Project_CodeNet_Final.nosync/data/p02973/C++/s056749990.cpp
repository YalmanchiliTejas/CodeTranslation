#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    deque<int> dq;
    for(int i = 0; i < n; i++){
        int idx = lower_bound(dq.begin(), dq.end(), A[i]) - dq.begin();
        if(idx == 0){
            dq.push_front(A[i]);
        }else{
            dq[idx - 1] = A[i];
        }
    }

    cout << dq.size() << endl;

    return 0;
}