#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> A(N);
    for (int i=0;i<N;++i)cin >> A[i];
    multiset<int> s;
    for (int i=0;i<N;++i){
        auto itr=s.lower_bound(A[i]);
        if (itr==s.begin()) s.insert(A[i]);
        else s.erase(--itr),s.insert(A[i]);
    }
    cout << s.size() << endl;
}