#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin>>h.at(i);
    }
    int count=1;
    int high = h.at(0);
    for(int i=0; i<n-1; i++){
        high = max(high, h.at(i));
        if(h.at(i+1) >= high){
            count++;
        }
    }
    cout << count << endl;
}
