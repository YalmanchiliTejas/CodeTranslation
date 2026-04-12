#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    deque<int> dq;
    for (int i = 0; i < N;i++){
        int t;
        cin >> t;
        int x = lower_bound(dq.begin(), dq.end(), t) - dq.begin();
        if(x == 0)
            dq.push_front(t);
        else
            dq[x - 1] = t;
    }
    cout << (int)dq.size() << endl;
    return 0;
}