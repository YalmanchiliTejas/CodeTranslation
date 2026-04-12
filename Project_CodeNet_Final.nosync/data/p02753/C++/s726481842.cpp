#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; } 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
using Graph = vector<vector<int>>;
queue<int> quex,quey;
const int MOD = 1000000007;




int main(){
    int a,b;
    string s,t;

    char u[3];
    for(int i=0;i<3;i++){
        cin >> u[i];
    }
    if(u[0]==u[1] && u[1]==u[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
}