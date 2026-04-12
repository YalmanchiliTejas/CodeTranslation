#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()
template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    int n;
    cin >> n;
    vector<int> a(n), ev, od;
    for(int i=0; i<n; ++i){
        cin >> a[i];

        if(i&1)
            od.push_back(a[i]);
        else
            ev.push_back(a[i]);
    }


    if(n&1){
        reverse(all(ev));
        for(auto x:ev)
            cout << x << " ";
        for(auto x:od)
            cout << x << " ";
    }
    else{
        reverse(all(od));
        for(auto x:od)
            cout << x << " ";
        for(auto x:ev)
            cout << x << " ";
    }
}