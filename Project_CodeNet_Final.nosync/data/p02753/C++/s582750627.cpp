#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 100000007;
using Graph = vector<vector<int>>;

int main(){
    string S;
    cin >> S;
    bool bus = true;
    if(S=="AAA"||S=="BBB") bus = false;
    if(bus) cout << "Yes" << endl;
    else cout << "No" << endl;
}