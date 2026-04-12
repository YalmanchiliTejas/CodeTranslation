#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>

#define rep(i, n) for(int i=0;i<n;i++)

typedef int long long ll;
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;

int main() {
    int n;
    cin>>n;
    vector<int> y(n);
    rep(i,n){
        cin>>y[i];
    }
    int p=y[0];
    int ans=1;
    for(int i=1;i<n;i++){
        if(y[i]>=p){
            ans++;
            p=y[i];
        }
    }
    cout<<ans<<endl;




    return 0;
}
