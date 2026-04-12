// g++ macro.cpp -std=c++14
#include <bits/stdc++.h> //STL include
typedef long long ll;// long long int
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;//namespace

#define dump(x)  cout << #x << " = " << (x) << endl;// debug cout
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl;
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)// for macro
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define CIN(x) int x;cin>>x;
#define COUT(x) cout<<(x)<<endl;

#define VECCIN(x) for(auto&youso_: (x) )cin>>youso_;
#define VECCOUT(x) for(auto&youso_: (x) )cout<<youso_<<" ";cout<<endl;

#define ALL(obj) (obj).begin(),(obj).end()// iterator

#define P pair<int,int>
#define V vector<int>

#define pb(a) push_back(a)//push_back
#define mp make_pair// make_pair


int main(){

    string s;
    cin>>s;
    cout<<((s=="a"||s=="i"||s=="u"||s=="e"||s=="o")?"vowel":"consonant")<<endl;
    return 0;
}
