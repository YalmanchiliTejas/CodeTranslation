#include<bits/stdc++.h>
using namespace std;
#define     int                long long
#define     ll                 long long
#define     start              int t;cin>>t;while(t--)
#define     f(n)               for(ll i=0;i<n;i++)
#define     fk(i,k,n)          for(ll i=k;i<=n;i++)
#define     al(s)              s.begin(),s.end()
#define     mp                 make_pair
#define     isvowel(a)         (a=='a' or a=='e' or a=='o' or a=='i' or a=='u')
#define     pb                 push_back
#define     ln                 cout<<"\n"
#define     sum(v)             accumulate(v.begin(), v.end(), 0ll)
#define     db1(x)           cout<<(#x)<<" is "<<x<<endl
#define     db2(x,y)           cout<<(#x)<<" is "<<x<<endl<<(#y)<<" is "<<y<<endl
#define     MOD                1000000007
#define     mii                map<int,int>
#define     vi                 vector<int>
#define     vii                vector<pair<int, int> >

const int N=2e5+20;
void print(vector<int> v, int n){f(n){cout<<v[i]<<" ";}}

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);
   /* #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif    */
}

int32_t main()
{
    run();
    
    string s;
    cin>>s;
    int x=count(al(s),'A');
    int y=count(al(s),'B');

    if(x and y)
        cout<<"Yes";
    else
        cout<<"No";
    ln;
}