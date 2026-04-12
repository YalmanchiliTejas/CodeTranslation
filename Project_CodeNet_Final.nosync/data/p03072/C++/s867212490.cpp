#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin>>h[i];
    }
    int ans=1;
    int ma=h[0];
    for(int i = 1; i < n; i++){
        if(ma<=h[i])ans++;
        ma = max(ma,h[i]);
    }
    cout<<ans<<endl;

    return 0;
}