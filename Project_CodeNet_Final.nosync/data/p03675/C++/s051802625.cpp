#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#include <list>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;
const int DIV = 1e9+7;

int n;
int in;

int main(){
    list<int> ans;
    cin >> n;
    if(n % 2 == 0){
        rep(i,n){
            cin >> in;
            if(i % 2 == 0){
                ans.push_back(in);
            }
            else{
                ans.push_front(in);
            }
        }
    }
    else{
        rep(i,n){
            cin >> in;
            if(i % 2 == 1){
                ans.push_back(in);
            }
            else{
                ans.push_front(in);
            }
        }
    }
    for(auto ou: ans){
        cout << ou << " ";
    }
    cout << endl;
    return 0;
}
