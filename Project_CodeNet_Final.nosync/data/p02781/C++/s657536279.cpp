//#pragma GCC optimize("Ofast")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef tree < int , null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> TREE;
#define ll long long
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pss pair<short,short>
#define pld pair<long double,long double >
#define ld long double
#define piii  pair<pii,int>
#define vii vector<pair<int,int> >
#define st first
#define nd second
#define pll pair<ll,ll>
#define speed ios::sync_with_stdio(false);cin.tie();cout.tie();
#define M_PI 3.14159265358979323846
//#define int long long
const int mod=1000000007;
//const int mod=1009;
//const int mod=998244353;
const int inf=1000000009;
const long long INF=1000000000000000009;
const long long big=1000000000000000;
const long double eps=0.000000000000000000001;
using namespace std;
ll DP[105][5],S[105][5];
int main()
{
    speed
    string napis;
    cin>>napis;
    reverse(napis.begin(),napis.end());
    int n=napis.size();
    napis='#'+napis;
    int k;
    cin>>k;
    S[0][0]=1;
    DP[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int a=napis[i]-'0';
        for(int j=0;j<=k;j++)
        {
            S[i][j]=S[i-1][j];
            if(j!=0)
                S[i][j]+=(ll)9*S[i-1][j-1];
            if(a!=0)
            DP[i][j]=S[i-1][j];
            else
                DP[i][j]=DP[i-1][j];
            if(j!=0)
            {
                if(a!=0)
                    DP[i][j]+=(ll)(a-1)*S[i-1][j-1]+DP[i-1][j-1];
            }

      //  cout<<i<<" "<<j<<" "<<DP[i][j]<<" "<<S[i][j]<<endl;
        }
    }
    cout<<DP[n][k];
    return 0;
}
