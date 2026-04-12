#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
const int maxn = 100005;
const int inf = 1000000007;

int main() {
   // freopen("in.cpp","r",stdin);
    int x,y;
    cin>>x>>y;
    cout<<setprecision(10)<<x*y*1.0/(x+y)<<endl;
    return 0;
}
