/*input
6
0 6 7 6 7 0
*/
#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define putcx putchar_unlocked
#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define ff(n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
#define LLINF LLONG_MAX
using namespace std;
#define M 1000000007
#define pi acos(-1)

int main()
{
    int n;
    cin >> n;
    vi a(n),b;
    ff(n) cin>>a[i];

    if(n%2==0){
        vi ss,bs;
        for(int i=1;i<n;i+=2) ss.pb(a[i]);

        reverse(all(ss));

        for(int i=0;i<n;i+=2) bs.pb(a[i]);

        //reverse(all(bs));
        for(auto i:ss) cout<<i<<" ";

        for(auto i:bs) cout<<i<<" ";

    }
    else{
        vi ss,bs;
        for(int i=1;i<n;i+=2) ss.pb(a[i]);

        

        for(int i=0;i<n;i+=2) bs.pb(a[i]);
            reverse(all(bs));
        //reverse(all(bs));
        for(auto i:bs) cout<<i<<" ";

        for(auto i:ss) cout<<i<<" ";

    }
}
