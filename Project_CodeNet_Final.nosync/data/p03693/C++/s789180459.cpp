#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

ll R,G,B;

void solve(){
    if((R*100+G*10+B)%4==0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(){
    cin >> R >> G >> B;

    solve();
}
