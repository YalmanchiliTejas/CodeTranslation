#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
typedef long long ll;

list<int> b;

int main() {
    int n;
    cin >> n;
    ll a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        if(i%2==0) b.push_back(a[i]);
        else b.push_front(a[i]);
    }
    if(n%2==0){
        cout << b.front();
        b.pop_front();
        while(!b.empty()){
            cout << ' ' << b.front();
            b.pop_front();
        }
        cout << endl;
    }
    else{
        cout << b.back();
        b.pop_back();
        while(!b.empty()){
            cout << ' ' << b.back();
            b.pop_back();
        }
        cout << endl;
    }
}