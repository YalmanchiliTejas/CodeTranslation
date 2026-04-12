#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
//a#define ll unsigned long long
#define int long long int
#define vi vector <int >
#define vvi vector < vector < int >  >
#define vii vector < pii >
#define vll vector <ll >
#define pii pair <int, int>
#define pdd pair< double, double>
#define piii pair < pii, int > 
#define pll pair<ll, ll >
#define umap unordered_map
#define pb push_back
#define pq priority_queue
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define fore(i,c) for(int i = 1; i <= (int)c; i++)
#define rep(i,b,c) for(int i = (int)b; i < (int)c; i++)
//#define double long double
#define a first
#define b second


int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);

    string s;
    cin >> s;
    bool b = false, a = false;
    for(auto x:s){
        if(x == 'A'){
            a = true;
        }else if(x == 'B')
            b = true;
    }    

    if(b && a) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
