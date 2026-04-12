#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int& e: a) cin>>e;

    deque<int> b;
    for(int i=0; i<n; ++i) {
        if (i%2)
            b.push_front(a[i]);
        else
            b.push_back(a[i]);
    }
    while (b.size()) {
        if (n%2) {
            cout<<b.back()<<' ';
            b.pop_back();
        }
        else {
            cout<<b.front()<<' ';
            b.pop_front();
        }
    }
    cout<<endl;
}

