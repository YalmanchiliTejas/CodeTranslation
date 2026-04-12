#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <cmath>
#include <cassert>
#include <cstdio>
 
// #include <unordered_set>
// #include <unordered_map>
 
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
 
#define pb push_back
#define mp make_pair
 
int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int lcm(int a,int b){int c=gcd(a,b);a/=c;return a*b;}
 
typedef std::pair<int, int> P;
typedef long long ll;
typedef long double ld;
 
const int MOD = 1000000007;
const int INF = 1e9;
const ll LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
 
 
using namespace std;
 
#define N 1000000
int arr[N];
int a[N];
 
signed main(int argc, char const *argv[])
{
    int x,y,z;
    cin>>x>>y>>z;

    REP(i,1000007){

        int tmp=i*(y+z)+z;
        if(tmp==x){
            // cout<<"match"<<endl;
            cout<<i<<endl;
            break;
        }else if(tmp>x){
            cout<<i-1<<endl;
            break;
        }
    }
    return 0;
}