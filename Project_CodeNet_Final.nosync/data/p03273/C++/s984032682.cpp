#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

int main(){
    lli h,w;
    string s;
    vector<string> vec;
    vector<lli> atu;
    lli i,j=0;
    cin>>h>>w;
    rep(i,0,h){
        cin>>s;
        if(s.find('#')!=string::npos){
            vec.push_back(s);
        }
    }
    rep(i,0,w){
        lli find=0;
        rep(j,0,vec.size()){
            if(vec[j][i]=='#'){
                find++;
            }
        }
        if(find!=0){
            atu.push_back(i);
        }
    }
    rep(i,0,vec.size()){
        rep(j,0,atu.size()){
            cout<<vec[i][atu[j]];
        }
        cout<<endl;
    }
}
