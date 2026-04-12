#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long long int llint;
#define MM 1000000000
#define MOD MM+7
#define pi pair<int,int>
#define pl pair<ll,ll>
const long double PI = acos(-1);
const long long INF = 1e15;
const ll DEP = (1LL << 50);
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
template<class T> bool chmax(T& a,T b){ if(a < b) {a = b; return true;} return false;}
template<class T> bool chmin(T& a,T b){ if(a > b) {a = b; return true;} return false;}
template<typename T>
T GCD(T x,T y){
    return y ? GCD(y,x%y) : x;
}
template<typename T>
string toString( const T &a ){
    ostringstream oss;
    oss << a;
    return oss.str();
};


/* 
void toporogical_sort(){
    for(int i = 0; i < v; i++){
        if(!In[i].size()) Q.push(i);
    }
    while(!Q.empty()){
        int t = Q.front(); 
        Q.pop();
        ans.push_back(t);
        for(int i = 0; i < Out[t].size(); i++){
            int nx = Out[t][i];
            int size = In[nx].size();
            for(int j = 0; j < size; j++){
                if(In[nx][j] == t){
                    In[nx].erase(In[nx].begin()+j);
                    break;
                }
            }
            if(!In[nx].size()) Q.push(nx);
        }
    }
}
*/

int N; 
int main(){
    while(true){
        cin >> N;
        if(N == 0) break;
        int a, mn = MM,mx = 0,ans = 0;
        for(int i = 0; i < N; i++){
            cin >> a;
            mn = min(mn,a);
            mx = max(mx,a);
            ans += a;
        }
        ans -= (mn+mx);
        ans /= (N-2);
        //cout << "ans=";
        cout << ans << endl;
    }
}
