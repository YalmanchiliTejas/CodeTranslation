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
int main(){
    int n;
    vector<int> hotel;
    int max = 0, ans = 0;

    cin >> n;
    REP(i, n){
        int tmp;
        cin >> tmp;
        hotel.pb(tmp);
    }

    REP(i,n){
        if(hotel[i] >= max){
            max = hotel[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
