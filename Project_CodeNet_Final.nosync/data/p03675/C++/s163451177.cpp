#include <bits/stdc++.h>

using namespace std;
int main() {
    deque<int>d, dd;
    int n;
    int x;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        if(i % 2 == 1){
            d.push_front(x);
            dd.push_back(x);
        }
        else {
            d.push_back(x);
            dd.push_front(x);
        }
    }
    if(n % 2 == 0){
    for(int i = 0; i < n - 1; ++i){
        cout << d[i] << " ";
    }
    cout << d[n - 1] <<endl;
    }
    else{
        for(int i = 0; i < n - 1; ++i){
        cout << dd[i] << " ";
        }
        cout << dd[n - 1] <<endl;
    }
    return 0;
}
