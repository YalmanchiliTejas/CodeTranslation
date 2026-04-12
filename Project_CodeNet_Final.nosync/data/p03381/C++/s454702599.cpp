//Power Of Ninja Go
#include <bits/stdc++.h>
//#ifdef atom #else #endif
using namespace std;
typedef long long ll; typedef pair<int, int> ii; typedef vector<int> vi; typedef vector< ii > vii;
#define X first
#define Y second
#define pb push_back
vector< ii > vec;
const int maxn = 2e5+5;
int ans[maxn];
int main()
{
    int n; cin >> n;
    for(int i = 0; i< n; i++)
    {
        int x; cin >> x;
        vec.pb(ii(x, i));
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i< n/2; i++)
    {
        ans[vec[i].Y] = vec[n/2].X;
    }
    for(int i = n/2; i< n; i++)
    {
        ans[vec[i].Y] = vec[n/2-1].X;
    }
    for(int i = 0; i< n; i++) cout << ans[i] << endl;
}
