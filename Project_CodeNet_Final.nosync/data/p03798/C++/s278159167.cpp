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
int n;
string s;
string res1 = "SS", res2 = "SW", res3 = "WS", res4 = "WW";

int cal(string res){
    for (int i = 1; i < n;i++){
        if(res[i]=='S'){
            if(s[i]=='o'){
                res += res[i - 1];
            }
            else{
                if(res[i-1]=='S')
                    res += 'W';
                else
                    res += 'S';
            }
        }else{
            if(s[i]=='o'){
                if(res[i-1]=='S')
                    res += 'W';
                else
                    res += 'S';
            }else{
                res += res[i - 1];
            }
        }
    }
    if(res[0]==res[res.size()-1]){
        string t=res.substr(0,n);
        if(s[0]=='o'&&t[0]=='S'){
            if(t[1]==t[t.size()-1]){
                cout<<t<<endl;
                exit(0);
            }
        }else if(s[0]=='o'&&t[0]=='W'){
            if(t[1]!=t[t.size()-1]){
                cout<<t<<endl;
                exit(0);
            }
        }else if(s[0]=='x'&&t[0]=='S'){
            if(t[1]!=t[t.size()-1]){
                cout<<t<<endl;
                exit(0);
            }
        }else{
            if(t[1]==t[t.size()-1]){
                cout<<t<<endl;
                exit(0);
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    cal(res1);
    cal(res2);
    cal(res3);
    cal(res4);
    cout << -1 << endl;
}
