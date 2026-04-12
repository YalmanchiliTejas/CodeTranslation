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
    char hoge;
    int a,b;
    vector<pii>v;
    while(cin>>a>>hoge>>b, a+b)
        v.push_back(pii(b,a));
    sort(all(v),greater<pii>());
    int rank[10000];
    int maxi=v[0].first;
    rank[0]=1;
    int now=1;
    for(int i=1; i<v.size(); i++){
        if(v[i].first==maxi){
            rank[i]=now;
        }else{
            maxi=v[i].first;
            now++;
            rank[i]=now;
        }
    }
    int n;
    while(cin>>n){
        for(int i=0; i<v.size();i++){
            if(n==v[i].second){
                cout<<rank[i]<<endl;
            }
        }
    }
}