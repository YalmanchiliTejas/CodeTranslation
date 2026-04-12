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
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>
using namespace std;
#define All(v) (v).begin(),(v).end()
const long long mod = 1000000007;
const long long inf = mod*mod;
const int MAXS = 114514;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
signed main(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    string res = "";
    for(char c='a';c<='z';c++){
        int m = 10000;
        for(auto str:s){
            int cnt = 0;
            for(int i=0;i<str.size();i++){
                if(str[i]==c)cnt++;
            }
            m=min(cnt,m);
        }
        for(int i=0;i<m;i++){
            res+=c;
        }
    }
    cout<<res<<endl;
}