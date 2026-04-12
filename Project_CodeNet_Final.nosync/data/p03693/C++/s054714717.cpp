#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>
using namespace std;
using Int = long long;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,f,t) for(int i=f;i<t;i++)
#define P(r) do{cout<<#r": ";for(const auto &i:r){cout<<i<<" ";}cout<<endl;}while(0)
int main()
{
    int r, g, b; cin >> r >> g >> b;
    cout << ((r*100 + g*10+b)%4==0?"YES":"NO" )<< endl;
    return 0;
}