#include<bits/stdc++.h>
#define ll long long
#define endl "\n"

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);

#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector< vector<long long>>
#define mi map<int,int>
#define pi pair<int,int>

#define Fori(i,a,b) for(int i=a; i<b; i++)
#define Ford(i, a, b) for(int i=a; i>=b; i--)

#define pb push_back
#define mp make_pair

#define read(a, n) for(int i=0; i<n; i++) cin >> a[i];
#define print(x) cout << "X: == " << x << endl;
#define printMap(a) for(auto it=a.begin() ; it!= a.end() ; it++) {cout << it->first << "  " << it->second << endl; }
#define printVector(a) for(auto it = a.begin() ; it!= a.end() ;it++) {cout << *it << endl;}

#define MOD 1000000007
using namespace std;
int main() {
    IOS
    int t;
    cin >> t;
    if(t >= 30 ) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }   
}