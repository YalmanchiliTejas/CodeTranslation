#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
const int Dx[8] = {0,1,1,1,0,-1,-1,-1}, Dy[8] = {-1,-1,0,1,1,1,0,-1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
int a, b, c, x, y;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >>a>>b>>c>>x>>y;
    if(a+b<=2*c){
        cout<<a*x+b*y<<"\n";
        return 0;
    }
    else{
        int ans;
        if(x>y){
            ans=2*c*y+a*(x-y);
        }
        else{
            ans=2*c*x+b*(y-x);
        }
        ans=min(ans,2*c*max(x,y));
        cout <<ans<< "\n";
    return 0;
    }
}