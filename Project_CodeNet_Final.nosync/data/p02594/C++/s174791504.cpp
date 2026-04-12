#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    if(n >= 30){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
