#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,l,n) for(int i=(l);i<(n);i++)

template<class T>
using vt = vector<T>;
template<class T>
using vvt = vector<vector<T>>;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    int card = 100*r + 10*g + b;
    if(card%4==0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return  0;
}


