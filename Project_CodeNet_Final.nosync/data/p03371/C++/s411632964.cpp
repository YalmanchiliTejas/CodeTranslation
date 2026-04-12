#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()

#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
template <typename T>
void print(T x)
{
    std::cout << x << '\n';
}

//typedef long long ll;
#define TENNINE 1000000005
#define TENFIVE 100005
//#define int long long

int a,b,c,x,y;

signed main()
{
    cin>>a>>b>>c>>x>>y;

    if(x==0&&y==0){
        cout <<0<<endl;
        return 0;
    }

    if(y==0){
        cout << min(a*x,2*c*x)<<endl;
        return 0;
    
    }

    if(x==0){
        cout <<min(b*y,2*c*y)<<endl;
    }

    int ans=1e9;
    rep(i,100001){
        int temp = i*2*c+max(0,(signed)(x-i))*a+max(0,(signed)(y-i))*b;
        ans = min(ans,temp);
    }

    cout <<ans<<endl;

    return 0;
}
