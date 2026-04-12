#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <tuple>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <iterator>
#include <array>
#include <memory>
#include <stack>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
#define MAX 9999999
using namespace std;
typedef pair<int, int> pii;
typedef pair<double,double>pdd;
typedef pair<ll,ll>pll;
char hoge[]="abcdefghijklmnopqrstuvwxyz";
int main(){
    int n; cin>>n;
    vector<string>s;
    rep(i,n){
        string t; cin>>t;
        s.push_back(t);
    }
    vvi v(n,vi(29,0));
    rep(i,n)rep(j,s[i].size()){
        v[i][s[i][j]-'a']++;
    }
    string ans;
    for(int i=0; i<27; i++){
        int j=0;
        int cnt=v[j][i];
        for(; j<n;j++){
            cmin(cnt,v[j][i]);
        }
        if(!cnt)continue;
        rep(k,cnt)
        ans.push_back(hoge[i]);
    }
    cout<<ans<<endl;
}