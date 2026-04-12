#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < (n);i++)
#define lint long long
const lint mod=1e9+7;
const lint inf=2.19e15+1;
const long double eps=1e-10;
template <class T,class U>bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}

signed main(){
    int x;
    cin >> x;
    if (x >= 30){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}