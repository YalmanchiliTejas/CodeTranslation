#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <unordered_map>
#include <string.h>
#include<iomanip>
#include <iterator>
#include <locale>

#define all(a) a.begin(),a.end()
#define VV(T) vector<vector< T > >
#define rep(i,N) for(int i = 0; i <N; i++)
#define repsg(i,s,g) for(int i = s; i <g; i++)
#define name(x) #x
using namespace std;


const int INF = 10000000;
const long long INFL = (1LL<<40);
const int MOD = pow(10,9)+7;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

typedef long long ll,LL;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
typedef pair<int,int> pii;
typedef pair<LL, LL> pLL;


// vector入力
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
    for(T& x: vec) is >> x;
    return is;
}
// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec){
    for(int i=0; i<vec.size(); i++){
        os << vec[i] << ( i+1 == vec.size() ? "" : " " );
    }
    return os;
}

template< typename T >
struct edge{
    int src, to;T cost;
    edge(int to,T cost) :src(-1),to(to),cost(cost){}
    edge(int src, int to, T cost) :src(src),to(to),cost(cost){}edge
    &operator=(const int &x){
        to =x;
        return *this;
    }
    operator int() const{ return to;}
};



int main() {
    int h,w;cin>>h>>w;
    vector<string> s(h);cin>>s;
   
    int rows[h+1];rep(i,h+1)rows[i]=0;
    int cols[w+1];rep(i,w+1)cols[i]=0;
    
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#'){rows[i] = 1;cols[j]=1;}
        }
    }
    
    rep(i,h){
        string out;
        rep(j,w){
            if(rows[i]==1 && cols[j]==1)out+=s[i][j];
        }
        if(out.size()!=0)cout<<out<<endl;
    }
    

    return 0;
}



