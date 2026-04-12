#pragma GCC optimize("O3")

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pi;
tree<int,int,greater<int>,rb_tree_tag,tree_order_statistics_node_update> map_t;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); ++i)
#define pb push_back
#define sz(x) (int)x.size()
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define REV(x) reverse(x.begin(),x.end())
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int aCnt=0;
    int bCnt=0;
    F0R(i,3)
    {
        if(s[i]=='A')
            aCnt++;
        if(s[i]=='B')
            bCnt++;
    }
    if(aCnt && bCnt)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
