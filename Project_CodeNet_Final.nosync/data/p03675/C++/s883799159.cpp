#include "bits/stdc++.h"
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a.at(i);
    if(n % 2){
        for(int i = 0; i < (n+1)/2; i++){
            if(i) cout << " ";
            cout << a.at(n-1-2*i);
        }
        for(int i = 0; i < n/2; i++){
            cout << " " << a.at(1+2*i);
        }
        cout << endl;
    }else{
        for(int i = 0; i < n/2; i++){
            if(i) cout << " ";
            cout << a.at(n-1-2*i);
        }
        for(int i = 0; i < n/2; i++){
            cout << " " << a.at(2*i);
        }
        cout << endl;
    }
    return 0;
}