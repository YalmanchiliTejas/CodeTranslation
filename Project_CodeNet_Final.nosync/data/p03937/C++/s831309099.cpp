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

const int INF = INT_MAX;
const long long INFL =LONG_LONG_MAX;
const double PI = atan(1)*4;
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


int main() {
    int h,w;cin>>h>>w;
    vector<string> A(h);
    rep(i,h)cin>>A[i];
    int count = 0;
    rep(i,h)rep(j,w){if(A[i][j]=='#')count++;}
    
    if(count ==h+w-1) cout<<"Possible"<<endl;
    else puts("Impossible");
    
    return 0;
}






