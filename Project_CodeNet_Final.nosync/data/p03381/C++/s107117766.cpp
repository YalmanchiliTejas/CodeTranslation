#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        v.push_back(x);
    }
    auto sorted = v;
    sort(sorted.begin(), sorted.end());
    int left = sorted[n/2-1], right = sorted[n/2];
    for(int i=0;i<n;++i){
        if(v[i] >= right)cout << left;
        else cout << right;
        cout << endl;
    }

    return 0;
}