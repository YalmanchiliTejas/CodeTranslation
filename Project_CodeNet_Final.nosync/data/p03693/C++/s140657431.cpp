#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
typedef pair<int,int> P;
#define mod 1000000007



int main(){
    int r,g,b;
    cin >> r >> g >> b;
    int x=10*g+b;
    if(x%4==0) cout <<"YES" <<endl;
    else cout << "NO" << endl;
    return 0;
}