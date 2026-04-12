#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    deque<int> dq;
    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int position = lower_bound(dq.begin(), dq.end(), a) - dq.begin();
        if(0 == position){
            dq.push_front(a);
        }else{
            dq[position - 1] = a;
        }
    }

    cout << dq.size() << endl; 
    return 0;
}