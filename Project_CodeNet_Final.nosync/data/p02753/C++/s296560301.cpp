#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
const int RANDOM1 = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return hash<int>{}(x ^ RANDOM1); }
};
#define ll long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define deb(x) cout<<#x<<" : "<<x<<"\n";
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\n";
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
#define clr fflush(stdout)
//#define clr cout.flush();
#define N 100001
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
int main()
{
    AKASH_PATEL;
    SVNIT_SURAT;
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
    return 0;
}



