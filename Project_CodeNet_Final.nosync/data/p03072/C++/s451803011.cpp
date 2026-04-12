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
int n;
int h[20];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) cin>>h[i];
    int hight=h[0];
    int ans=1;
    for(int i=1;i<n;i++){
        if(hight<=h[i]){
            ans++;
            hight=h[i];
        }
    }
    cout << ans << "\n";
}