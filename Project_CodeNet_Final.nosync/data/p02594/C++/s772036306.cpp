#include<bits/stdc++.h>
using namespace std;                void iosbase(void);
typedef  long long int     ll;      typedef long double                            db;
typedef  vector<int>       vi;      typedef priority_queue<int>                    MAXHEAP;
typedef  pair<int, int>    pii;     typedef priority_queue<int, vi, greater<int>>  MINHEAP;
#define  int               ll
#define  ff                first
#define  ss                second
#define  pb                push_back
#define  si(x)             (int)x.size()
#define  minv(m,n)         *min_element(m,n)
#define  maxv(m,n)         *max_element(m,n)
#define  deb(x)            cout<<"> "<<#x<<" : "<<x<<endl;
#define  mem(a,x)          memset(a,x,sizeof(a))
#define  rep(i,n)          for(int i=0;i<n;i++)
#define  prs(x,y)          fixed<<setprecision(y)<<x
#define  show(a)           for(auto x:a){cout<<x<<" ";}cout<<endl;
#define  showmap(a)        for(auto x:a){cout<<x.ff<<" "<<x.ss<<endl;}
#define  showstack(a)      while(!a.empty()){cout<<a.top()<<endl;a.pop();}
const int sz = 1e5 + 5;

int32_t main()
{
    iosbase(); int tt = 1;
    //cin>>tt;
    for (int t = 1; t <= tt; t++)
    {
        int n;
        cin >> n;
        if ( n >= 30)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0 ;
}
void iosbase(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//freopen("in2.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
}
