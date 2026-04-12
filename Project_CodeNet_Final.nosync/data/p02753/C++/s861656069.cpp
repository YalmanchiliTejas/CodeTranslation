/*
 * Author: Anmol Choudhary
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep0(a,b) for(int a=0;a<b;a++)
#define rep1(a,b) for(int a=1;a<=b;a++)
#define repp(a,b,c) for(int a=b;a<c;a++)
#define in insert
#define len length()
#define si size()
#define lb lower_bound
#define ub upper_bound
#define beg begin()
#define en end()
#define f first
#define s second
#define pr(a) cout<<a
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
#define nextl cout<<"\n"
#define deb(x) cout<<#x<<"="<<x<<"\n"
#define deb2(x,y) cout<<"["<<#x<<"="<<x<<"] , ["<<#y<<"="<<y<<"]"<<"\n"
const ll mod = 1000000007;
const ll maxn = 100005;
const ll mm = 1e+18;
void solve()
{
    set<char>s;
    string ss;
    cin>>ss;
    rep0(i,3) s.in(ss[i]);
    if(s.si==1) pr("No");
    else pr("Yes");
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        //nextl;
    }
    return 0;
}
