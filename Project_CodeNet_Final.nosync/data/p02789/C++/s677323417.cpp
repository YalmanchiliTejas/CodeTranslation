#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <list>
#include <cmath>
using namespace std;
#define rep(i,m,n) for (int i = (int) (m); i < (int) (n); i++)
#define rep1(i,m,n) for (int i = (int) (m); i <= (int) (n); i++)
#define all(x)     (x).begin(), (x).end()
#define SZ(x)      ((int) (x).size())
long long int Max(long long int a,long long int b){
    if(a>=b)return a;
    else return b;
}
long long int comb(long long int n,long long int r){
    vector<vector<long long int> > v(n+1,vector<long long int>(n+1,0));
    long long int i,j;
    rep(i,0,n+1){
        v.at(i).at(0)=1;
        v.at(i).at(i)=1;
    }
    rep(i,0,n+1){
        rep(j,0,i)v.at(i).at(j)=v.at(i-1).at(j-1)+v.at(i-1).at(j);
    }
    return v.at(n).at(r);
}
int main(void){
    int N,M;
    cin>>N>>M;
    if(N==M)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}