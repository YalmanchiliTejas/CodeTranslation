
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <tuple>
using namespace std;

const double pi = acos(-1);
#define nyan cout << "(=^•ω•^=)" << endl;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define loop while(true)

int ans;
int n;

signed main(){
    cin>>n;
    if(n==3||n==5||n==7)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}