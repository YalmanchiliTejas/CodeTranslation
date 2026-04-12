#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;

lli n;
mat g;
mat s;
lli a,b;
vbl vis;
lli e,o;


lli depth(lli x,lli p){
    lli j = -1;
    lli sum = 0;
    s[x] = vll(g[x].size());
    for(lli i = 0;i < g[x].size();i++){
        if(g[x][i] == p){
            j = i;
            continue;
        }
        s[x][i] = depth(g[x][i],x);
        sum += s[x][i];
    }
    if(j >= 0) s[x][j] = n-sum-1;
    return sum + 1;
}



int main(){
    cin >> n;
    g = mat(n+1);
    s = mat(n+1);
    for(lli i = 0;i < n-1;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n%2 == 1){
        cout << "First" << endl;
        return 0;
    }
    depth(1,0);
    for(lli i = 1;i <= n;i++){
        lli t = 0;
        for(lli j = 0;j < s[i].size();j++){
            if(s[i][j] % 2 == 1) t++;
        }
        if(t >= 2){
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
    return 0;

}