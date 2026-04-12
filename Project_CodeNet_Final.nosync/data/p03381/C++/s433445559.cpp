#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<int> orig = v;
    sort(v.begin(), v.end());

    int mid1 = v[n/2-1], mid2 = v[n/2];

    for(int i=0;i<n;++i){
        if(orig[i] > mid1)cout << mid1;
        else cout << mid2;
        cout << endl;
    }

    return 0;
}
