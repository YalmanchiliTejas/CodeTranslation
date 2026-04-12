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
int main(){
    int n;
    int hoge=0;
    while(cin>>n,n){
        if(hoge++)cout<<endl;
        vector<pii>v;
        vector<string>amausa;
        rep(i,n){
            int gotiusa=0;
            string rabit; cin>>rabit;
            amausa.push_back(rabit);
            int kokoa,rize,tino; cin>>kokoa>>rize>>tino;
            gotiusa+=kokoa*3+tino;
            v.push_back(pii(gotiusa,-i));
        }
        sort(all(v),greater<pii>());
        rep(i,n)cout<<amausa[-1*v[i].second]<<","<<v[i].first<<endl;
    }
}