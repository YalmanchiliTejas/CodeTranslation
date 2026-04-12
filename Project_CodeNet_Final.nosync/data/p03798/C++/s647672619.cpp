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
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int Dy[8] = {-1,-1,0,1,1,1,0,-1};
int Dx[8] = {0,1,1,1,0,-1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;
int n;
string s;
char t[d5];
bool ok(char t[d5]){
    for(int i=1;i<n;i++){
        if((s[i]=='o'&&t[i]=='S')||(s[i]=='x'&&t[i]=='W')){
            t[i+1]=t[i-1];
        }
        else{
            if(t[i-1]=='S')t[i+1]='W';
            else t[i+1]='S';
        }
    }

    if(t[0]!=t[n])return false;
    if((s[0]=='o'&&t[0]=='S')||(s[0]=='x'&&t[0]=='W')){
        if(t[1]==t[n-1])return true;
        else return false;
    }
    else{
        if(t[1]!=t[n-1])return true;
        else return false;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cin>>n>>s;
    t[0]='S';t[1]='S';
    if(ok(t)){
        for(int i=0;i<n;i++)cout<<t[i];
        cout<<endl;
        return 0;
    }
    t[0]='S';t[1]='W';
    if(ok(t)){
        for(int i=0;i<n;i++)cout<<t[i];
        cout<<endl;
        return 0;
    }
    t[0]='W';t[1]='S';
    if(ok(t)){
        for(int i=0;i<n;i++)cout<<t[i];
        cout<<endl;
        return 0;
    }
    t[0]='W';t[1]='W';
    if(ok(t)){
        for(int i=0;i<n;i++)cout<<t[i];
        cout<<endl;
        return 0;
    }
    cout<<-1<<endl;
}
