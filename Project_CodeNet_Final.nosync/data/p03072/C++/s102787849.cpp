/**
 * 	author: MahfuzAhmed
 * 	created: 09.08.2019 
**/

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define forn(var,from,to) for(int var=(from);var<(to);var++)
#define forx(var,from,to) for(int var=(from);var<=(to);var++)
#define fory(var,from,to) for(int var=(from);var>=(to);var--)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vvi vector<vi>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define all(p) p.begin(),p.end()
typedef long long ll;
//~ const double pi = 2*acos(0.0);
//~ const long long mod = 1e9+7;
//~ const int MAX_N = 1e6+5;

int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
       
    #ifdef _DEBUG
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    
    int n; cin >> n;
    int heights[n];
    
    forn(i, 0, n) cin >> heights[i];
    
    int b = heights[0];
    int cnt = 1;
    
    forn(i, 1, n){
        if(heights[i] >= b){
            cnt++;
            b = heights[i];
        }
    }
    
    cout << cnt << "\n";
    
    
    return 0;
}