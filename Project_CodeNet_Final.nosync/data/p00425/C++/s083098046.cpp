#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back


void solve(string s,int dice[6]){
    int ans[6]={};
    rep(i,6)ans[i]=dice[i];
    if(s=="North"){
        ans[0]=dice[1];
        ans[1]=dice[5];
        ans[4]=dice[0];
        ans[5]=dice[4];
    }
    if(s=="East"){
        ans[0]=dice[3];
        ans[2]=dice[0];
        ans[3]=dice[5];
        ans[5]=dice[2];
    }
    if(s=="West"){
        ans[0]=dice[2];
        ans[2]=dice[5];
        ans[3]=dice[0];
        ans[5]=dice[3];
    }
    if(s=="South"){
        ans[0]=dice[4];
        ans[1]=dice[0];
        ans[4]=dice[5];
        ans[5]=dice[1];
    }
    if(s=="Right"){
        ans[1]=dice[2];
        ans[2]=dice[4];
        ans[3]=dice[1];
        ans[4]=dice[3];
    }
    if(s=="Left"){
        ans[1]=dice[3];
        ans[2]=dice[1];
        ans[3]=dice[4];
        ans[4]=dice[2];
    }
    
    rep(i,6){
        dice[i]=ans[i];
    }
}

int main() {
    int n;
    while(cin>>n){
        if(n==0)break;
        
        int dice[6]={};
        rep(i,6)dice[i]=i+1;

        int sum=1;
        rep(i,n){
            string s;
            cin>>s;
            solve(s,dice);

            sum+=dice[0];
        }//
        cout<<sum<<endl;
    
    }
    return 0;
}