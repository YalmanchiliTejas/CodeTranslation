#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n))
#define Vec(a,n) vector<string> (a)((n))
#define P pair<int,int>
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
using namespace std;
 
signed main(){
 
    int a,b;
    cin >> a ;
    if(a == 3 || a == 5 || a == 7){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}