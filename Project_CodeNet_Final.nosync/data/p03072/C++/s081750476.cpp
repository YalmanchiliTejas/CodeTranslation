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
static const int MAX = 100;
static const int INF = (1 << 23);

int main() {
    int n;
    cin>>n;
    int ans=0;
    int premax=0;
    rep(i,n){
        int a;
        cin>>a;
        if(i==0){
            ans++;premax=a;
        }else{
            if(premax<=a){ans++;premax=a;}
        }


    }
    cout<<ans<<endl;



    return 0;
}
