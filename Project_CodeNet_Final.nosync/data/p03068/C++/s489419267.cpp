#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned int ui;
#define All(v) (v).begin(),(v).end()
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define REPS(i,n) for(int i = 1; i <= (int)n; i++)
#define FOR(i,m,n) for(int i = m; i < n; i++)
#define FORS(i,m,n) for(int i = m; i <= n; i++)
#define INF 2e9
#define F first
#define S second
#define pb push_back
#define mp make_pair
struct speed{speed(){cin.tie(); ios::sync_with_stdio(false); cout << fixed << setprecision(18);}}speed;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main (){
    int n,k;
    string s;
    cin >> n >> s >> k;
    char tmp = s[k-1];
    REP(i,n){
        if(s[i] != tmp){
            s[i] = '*';
        }
    }
    cout << s << endl;
}