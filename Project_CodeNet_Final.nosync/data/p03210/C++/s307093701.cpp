#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)
#define rep1(i,n) for(int i=1 ; i<=n ; i++)
#define vi vector<int>
#define Sort(v) sort(v.begin(),v.end())
#define Reverse(v) reverse(v.begin(),v.end())

//const int MOD = 1000000007;
//const int INF = 1<<30;
using namespace std;

string yn(bool x){
    return x ? "YES" : "NO";
}

int main(){
    int x; cin >> x;
    bool ans = 0;
    if(x == 3 or x == 5 or x==7)ans = true;
    cout << yn(ans) << endl;
}







