#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll H, W;
    cin>>H>>W;
    string a[100];
    bool use[100][100];
    string allwhite="";
    rep(i, H) rep(j, W) use[i][j]=true;
    rep(i, H) cin>>a[i];
    rep(i, W) allwhite+=".";
    rep(i, H){
        if(a[i]==allwhite){
            rep(j, W) use[i][j]=false;
        }
    }
    rep(i, W){
        bool rem=true;
        rep(j, H) if(a[j][i]=='#') rem=false;
        if(rem) rep(j, H) use[j][i]=false;
    }
    rep(i, H){
        bool useline=false;
        rep(j, W){
            if(use[i][j]) useline=true, cout<<a[i][j];
        }
        if(useline) cout<<endl;
    }
    return 0;
}
