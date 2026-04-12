#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
typedef long long ll;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int main(){
    int n;cin >> n;
    string s;cin >> s;
    string res;
    int k;cin >> k;
    rep(i,n){
        if(s[i]!=s[k-1])res.push_back('*');
        else res.push_back(s[i]);
    }
    cout << res << endl;
    return 0;
}