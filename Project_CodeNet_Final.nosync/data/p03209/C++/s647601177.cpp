#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
ll MOD = 1e9 + 7;

int n;
ll x;
vector<ll> patty(51),all(51);


ll burger_count(int n, ll x){
    if(x == 0) return 0;
    if(n == 0) return 1;
    if(x == 1) return 0;
    else if(1 < x && x <= all[n] + 1) return burger_count(n-1,x-1);
    else if(x == all[n] + 2) return patty[n] + 1;
    else if(all[n] + 2 < x && x <= 2 * all[n] + 2) return burger_count(n-1,x - all[n] - 2) + patty[n] + 1;
    else if(x == 2 * all[n] + 3) return 2 * patty[n] + 1;
}


int main(){
    cin >> n >> x;
    patty[1] = 1;
    all[1] = 1;
    for(int i = 1;i < 50;i++){
        patty[i+1] = 2 * patty[i] + 1;
        all[i+1] = 2 * all[i] + 3; 
    }

    cout << burger_count(n,x) << endl;;

}