#include <bits/stdc++.h>

#define REP(i ,n) for(int i=0 ;i < n; i++)
#define REPB(i ,n) for(int i=n; i >= 0; i--)
#define FOR(i ,m ,n) for(int i=m; i < n; i++)
#define FORB(i, m, n) for(int i=m; i>= n; i--)
#define ll long long
#define pb push_back
#define popb pop_back
#define debug(i) cout << i << endl
using namespace std;

int n;

bool solve(vector<int> t){
    int dist = 0;

    REP(i,n){
        if(dist < 10 * i) return false;
        dist = max(dist, t[i] + 10*i);
    }
    return true;
}

int main(){
    cin >> n;
    vector<int> d;

    REP(i,n){
        int t;
        cin >> t;
        d.pb(t);
    }

    REP(i,2){
        bool a = solve(d);
        if(a == false){
            cout << "no" << endl;
            return 0;
        }
        
        reverse(d.begin(),d.end());
    }   

    cout << "yes" << endl;
    return 0;
}

