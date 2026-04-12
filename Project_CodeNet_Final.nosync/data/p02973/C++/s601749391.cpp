#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] *= -1;
    }
    vector<int> b;
    b.emplace_back(a[0]);
    for(int i = 1; i < n; i++){
        auto p = upper_bound(begin(b), end(b), a[i]);
        if(p == b.end()){
            b.emplace_back(a[i]);
        }else{
            *p = a[i];
        }
    }
    ans = b.size();
    cout << ans << endl;
    return 0;
}
