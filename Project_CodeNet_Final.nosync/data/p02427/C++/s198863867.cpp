#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define max0(a,b,c) max(max(a,b),c)
#define min0(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
using Graph = vector<vector<int>>;
typedef long long lint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<ull> ulvec;
typedef vector<double> dvec;
typedef vector<pair<int,int>> pvec;
typedef vector<pair<ll,ll>> plvec;
typedef vector<tuple<ll,ll,ll>> tvec;
typedef vector<string> svec;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        cout<<i<<':';
        for(int j=0;j<n;j++){
            if(i>>j&1) cout<<' '<<j;
        }
        cout<<endl;
    }
}
