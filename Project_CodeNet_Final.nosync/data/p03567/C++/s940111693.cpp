#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <functional> // std::function<void(int)>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int Dy[8] = {-1,-1,0,1,1,1,0,-1};
int Dx[8] = {0,1,1,1,0,-1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 111111;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    bool can=false;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='A'&&s[i+1]=='C')can=true;
    }
    if(can)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}