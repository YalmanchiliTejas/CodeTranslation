#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvi;
typedef unordered_map<int,int> uoii;
typedef unordered_map<string,int> uosi;

const int MOD = 1e9+7;

const int INF = 1e10;




int32_t main()
{
    IOS
    string s;
    cin>>s;
    bool ans=false;
    for(int i=0;i<2;i++){
        if(s[i]=='A'&&s[i+1]=='B'||s[i]=='B'&&s[i+1]=='A')
            ans=true;
    }
    if(ans)
        cout<<"Yes";
    else cout<<"No";


    return 0;
}
