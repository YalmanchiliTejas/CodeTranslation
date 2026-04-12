#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++)  cin >> h[i];
    vector<int> a{0};
    for(int i = 0; i < n; i++){
        if(a.back() <= h[i]) a.push_back(h[i]);
    }
    cout << a.size()-1;
}
