#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) ((v).begin(),(v).end())
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int n;cin >> n;
    string s;
    string test = "abcdefghijklmnopqrstuvwxyz";
    vector<string> vec(n);
    REP(i,n)cin >> vec[i];
    for(char x:test){
        int min1 = INF;
        REP(i,n){
            int num = count(vec[i].begin(),vec[i].end(),x);
            min1 = min(num,min1);
        }
        REP(k,min1)cout << x; 
    }
    cout << endl;
    return 0;
}