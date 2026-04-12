#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;
using ll=long long;
ll gcd(ll a,ll b){return (b==0?a:gcd(b,a%b));}
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,n) for(int i=a;i<n;i++)
constexpr ll INF=1000000011;

int main (){
    int n;
    cin >> n;

    cout << n*800 - n/15*200 << endl;
}