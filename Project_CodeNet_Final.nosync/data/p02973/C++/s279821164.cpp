#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>

#define rep(i, n) for(int i=0;i<n;i++)

typedef int long long ll;
using namespace std;
typedef pair<int, int> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
static const int MAX = 100;
static const int INF = (1 << 23);

template<class T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template<class T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }


int main() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    //priority_queue<pair<ll,int>> q;
    rep(i,n){
        cin>>a[i];

    }
    //sort(a.begin(),a.end());
    multiset<ll> p;
    p.insert(a[0]);


    for(int i=1;i<n;i++){
       // sort(p.begin(),p.end());
        auto c = p.lower_bound(a[i]);
       // cout<< (c-p.begin())<<"c"<<endl;
        if(c==p.begin()){
            p.insert(a[i]);
        }else{
            c--;
            p.erase(c);
            p.insert(a[i]);
        }
//        rep(i,p.size())cout<<p[i];
//        cout<<endl;

    }



  cout<<p.size()<<endl;


    return 0;
}
