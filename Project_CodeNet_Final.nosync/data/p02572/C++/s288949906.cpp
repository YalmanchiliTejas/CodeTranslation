#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
const int inf=2e3;
#define maxx 1005
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

ll findProductSum(ll A[], int n)
{
    ll array_sum = 0;
    for (int i = 0; i < n; i++)
        array_sum = (array_sum + A[i])%mod;

    ll array_sum_square = (array_sum* array_sum)%mod;

    ll individual_square_sum = 0;
    for (int i = 0; i < n; i++)
        individual_square_sum = (individual_square_sum+(A[i]*A[i])%mod)%mod;
    return (((array_sum_square- individual_square_sum+mod)%mod)*500000004)%mod;
}
int main(){
    FASTIO;
    int n;
    cin>>n;
    ll a[n];
    REP(i,0,n) cin>>a[i];
    cout<<findProductSum(a,n)<<endl;
    return 0;
}
