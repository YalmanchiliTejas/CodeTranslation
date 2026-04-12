// Author : Nachiket Kanore
// Institute : PICT, Pune

/*
 * 	Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid to fall...
 */

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <memory>
#include <random>
#include <cmath>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>

using namespace std;

#define int long long
#define endl '\n'
#define rep(x,s,e) for(int x=s;x<=(e);x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define precise(x) cout << fixed << setprecision(x)
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define mp make_pair
#define test int t; cin>>t; while(t--)
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
 
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
 
const int mod = 1e9+7;
const int inf = 1e18;
const int N = 2e5+20;


int32_t main(){
    FAST;
    
    string s;   cin >> s;
    rep(i,0,s.size()-2){
        if(s[i] == 'A' and s[i+1] == 'C')
            return cout << "Yes" , 0;
    }
    cout << "No";
    
    return 0;
}