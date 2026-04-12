#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stack>
#include <functional>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define rep(i,j,k) for(int i=j;i<k;i++)
#define Sort(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define vi vector<int>
#define INF 1000000000
#define MOD 1000000007
#define pb push_back
#define MP make_pair
typedef long long ll;
typedef std::pair<int,int> pii;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

using namespace std;

int main() {
    string s;
    string v="qwertasdfgzxcvb";
    //vector<char> v;
    //rep(i,0,s.length()) v.pb(vv[i]);
    while(cin>>s){
        if(s=="#")return 0;
        int ans=0;
        bool left;
        rep(i,0,s.length()){
            if(i==0){
                if(find(all(v),s[i])==v.end())left=false;
                else left=true;
            }else {
            if(find(all(v),s[i])!=v.end()){
                if(!left){
                    ans++;
                    left=true;
                }
            }else {
                if(left){
                    ans++;
                    left=false;
                }
            }}
        }
        cout<<ans<<endl;
    }
    return 0;
}

