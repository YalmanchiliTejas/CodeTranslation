#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n), d(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        d[i] = a[i];
    }

    sort(a.begin(), a.end());
    sort(d.begin(), d.end(), greater<int>());
    
    deque<int> dq, dq2;
    dq.push_back(a[0]);
    dq2.push_back(d[0]);
    int a_ptr = 1;
    int d_ptr = 0;
    int a_ptr2 = 0;
    int d_ptr2 = 1;
    for(int i = 0; i < n; ++i){
        dq.push_front(d[d_ptr]);
        dq2.push_front(a[a_ptr2]);
        if(dq.size() == n) break;
        ++d_ptr;
        ++a_ptr2;
        dq.push_back(d[d_ptr]);
        dq2.push_back(a[a_ptr2]);
        if(dq.size() == n) break;
        ++d_ptr;
        ++a_ptr2;
        dq.push_front(a[a_ptr]);
        dq2.push_front(d[d_ptr2]);
        if(dq.size() == n) break;
        ++a_ptr;
        ++d_ptr2;
        dq.push_back(a[a_ptr]);
        dq2.push_back(d[d_ptr2]);
        if(dq.size() == n) break;
        ++a_ptr;
        ++d_ptr2;
    }

    long long res = 0;
    long long res2 = 0;
    int prev = dq[0];
    int prev2 = dq2[0];
    for(int i = 1; i < n; ++i){
        int now = dq[i];
        int now2 = dq2[i];
        res += abs(now - prev);
        res2 += abs(now2 - prev2);

        prev = now;
        prev2 = now2;
    }



    cout << max(res, res2) << endl;

    return 0;
}