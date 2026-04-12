#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<int> si;
typedef map<int, int> mii;
#define INF (1<<29)

int main(){
    int x,y,z;
    cin>>x>>y>>z;

    int ans;
    ans=(x-z)/(y+z);


    cout<<ans<<endl;
    return 0;
}