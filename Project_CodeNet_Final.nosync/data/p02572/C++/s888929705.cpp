//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
#define y second
#define inf 1000000000000000000
#define N 1000000007
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.x<<','<< P.y<<')';}
template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}

set<int> zro;
set<int> one;
vector<vector<int>> g;
//edge cases when n=1,m=1.wrong variable in loop.if<->while;merge resize;LLONG_MAX
signed main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //#endif
    speed
    //global var
    int n,sum=0;
    cin>>n;
    int diff=0;
    for(int i=0;i<n;++i){
        int tmp;cin>>tmp;sum+=tmp;sum%=N;
        diff+=tmp*tmp;diff%=N;
    }
    int ans=(((((sum*sum)%N)-diff)*500000004)%N);
    ans+=N;
    ans%=N;
    cout<<ans<<"\n";
}
//try thinking from a different angle after spending some time
