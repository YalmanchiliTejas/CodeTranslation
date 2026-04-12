#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i){
        int k;
        cin >> k;
        auto it = lower_bound(a.begin(), a.end(), k);
        if(it == a.end()){
            cout << n << endl;
        }
        else{
            cout << it - a.begin() << endl;
        }
    }

    return 0;
}
