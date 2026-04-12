#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <bitset>
#include <cstdio>
#include <set>
#include <stack>
#include <queue>
#include <cassert>
#include <numeric>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)
#define rep1(i,n) for(int i=1 ; i<=n ; i++)
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int,int>
#define Sort(v) sort(v.begin(),v.end())
#define Reverse(v) reverse(v.begin(),v.end())
#define ALL(a)  (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
//#define int ll
typedef long long ll;

const int md = 1000000007;
const int INF = 1<<30;
using namespace std;

string yn(bool x){
    return x ? "YES" : "NO";
}


int main(){
    int n; cin >> n;
    int h = 0;
    int ans = 0;
    rep(i,n){
        int tmp; cin >> tmp;
        if(tmp >= h){
            ans++;
            h = tmp;
        }
    }

    cout << ans << endl;

}

