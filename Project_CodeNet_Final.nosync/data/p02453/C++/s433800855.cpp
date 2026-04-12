#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin() , v.end());
    int m;
    cin >> m;
    for(int i = 0; i< m; i++){
        int p;
        cin >> p;
        /*
        if(p >= v[n-1]){
            cout << n << endl;
        }
        else {
            auto itr = lower_bound(v.begin(), v.end(), p);
            cout << itr-v.begin() << endl;
        }
        */
        auto itr = lower_bound(v.begin(), v.end(), p) - v.begin();
        cout << itr << endl;
    }
}
