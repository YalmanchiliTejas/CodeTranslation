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
    deque<int> ans;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;

        if(!((i^n)&1)){
            ans.push_back(x);
        }
        else{
            ans.push_front(x);
        }
    }

    for(auto x:ans)
        cout << x << " ";
}