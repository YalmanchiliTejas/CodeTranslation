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
typedef pair<int, int> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
static const int MAX = 100;
static const int INF = (1 << 23);

int main() {
    int n;
    while(true){
        cin>>n;
        if(n==0)break;
        vector<int> v(n);
        int sum=0;
        rep(i,n){
            cin>>v[i];
            sum+=v[i];
        }
        sort(v.begin(),v.end());
        sum-=v[0];
        sum-=v[n-1];
        int ave=sum/(n-2);
        cout<<ave<<endl;


    }

    return 0;
}

