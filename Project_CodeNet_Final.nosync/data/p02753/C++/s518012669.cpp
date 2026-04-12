#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#ifndef ONLINE_JUDGE
#define deb(x) cout<<#x<<" : "<<x<<"\n";
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\n";
#define deb_arr(a,n) {cout<<#a<<":";for(int i=0;i<n;i++) {cout<<a[i]<<" ";} cout<<'\n';}
#define deb_mat(dist,n,m) {cout<<#dist<<"\n";for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<dist[i][j]<<" ";}cout<<'\n';}}
#else
#define deb(x) ;
#define debug(x,y) ;
#define deb_arr(a,n) ;
#define deb_mat(dist,n,m) ;
#endif
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define all(a) (a).begin(),(a).end()
#define bs binary_search
#define sz size()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double
#define clr fflush(stdout);
//#define clr cout.flush();
#define N 200001
#define fpr(i,a,b) for(int i=a;i<b;i++)
#define fdr(i,a,b) for(int i=a;i>b;i--)
#define repp(i,a,b,d) for(int i=a;i<b;i+=d)
#define repd(i,a,b,d) for(int i=a;i>b;i-=d)
#define LLMIN LLONG_MIN
#define LLMAX LLONG_MAX
#define AKASH_PATEL ios_base::sync_with_stdio(false);
#define SVNIT_SURAT cin.tie(NULL);cout.tie(NULL);
#define mset(x,a) memset(x,a,sizeof(x));
#define nl cout<<'\n';
#define print(c) cout<<c<<'\n';
#define setp(n) cout << fixed << setprecision(n)
#define take_arr(a,n) fpr(i,0,n) cin>>a[i];
#define print_arr(a,n) for(int i=0;i<n;i++) {cout<<a[i]<<" ";} cout<<'\n';
#define take_mat(mat,n,m) fpr(i,0,n) fpr(j,0,m) cin>>mat[i][j];
#define set_mat(mat,n,m,k) fpr(i,0,n) fpr(j,0,m) mat[i][j]=k;
#define print_mat(dist,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<dist[i][j]<<" ";}cout<<'\n';}
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > bool odd(T a) { return a&1; }
template< class T > bool even(T a) { return !(a&1); }
int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("../ip.txt", "r", stdin);
//    freopen("../op.txt", "w", stdout);
//#endif
    AKASH_PATEL;
    SVNIT_SURAT;

    int t=1;
    //cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int c=0;
        fpr(i,0,s.size())
        {
            if(s[i]=='A')
            {
                c++;
            }
        }
        if(c==0 || c==s.sz)
        {
            print("No")
        } else{
            print("Yes")
        }
    }
    return 0;
}



