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
#include <functional>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h,w;
    cin>>h>>w;
    string s[h];
    for(int i=0;i<h;i++)cin>>s[i];
    bool tate[h],yoko[w];
    for(int i=0;i<h;i++)tate[i]=true;
    for(int i=0;i<w;i++)yoko[i]=true;
    for(int i=0;i<10;i++)
    for(int i=0;i<h;i++){
        bool ok=false;
        for(int j=0;j<w;j++){
            if(s[i][j]=='#')ok=true;
        }
        tate[i]=ok;
    }
    for(int j=0;j<w;j++){
        bool ok=false;
        for(int i=0;i<h;i++){
            if(s[i][j]=='#')ok=true;
        }
        yoko[j]=ok;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(tate[i]&&yoko[j])cout<<s[i][j];
        }cout<<endl;
    }
}