#include <bits/stdc++.h>
using namespace std;
int n,p1;
deque<int> dq;
int main() {
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>p1;
        if ((i%2)==0) dq.push_back(p1);
        else dq.push_front(p1);
    }
    vector<int> v;
    while (!dq.empty()) {
        v.push_back(dq.front());
        dq.pop_front();
    }
    if (n%2==1) reverse(v.begin(),v.end());
    for (int i=0; i<v.size(); i++) cout<<v[i]<<' ';
    cout<<'\n';
}