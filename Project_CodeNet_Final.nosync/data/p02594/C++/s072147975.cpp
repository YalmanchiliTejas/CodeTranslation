#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF 1000000000 // 10^9
#define mod 1000000007
#define EPS 0.000000001 //10^-9
#define rep(i,a,b) for((i)=(a);(i)<=(b);(i++))
#define pb push_back 
using namespace std;
typedef long long ll;
class node
{
public:
    int value;
    node *left;
    node *right;
};
class node* newnode(int value)
{

    node* a=(node*)malloc(sizeof(node));
    a->value=value;
    a->left=NULL;
    a->right=NULL;
    return a;
};

ll power(ll x,ll n)
{
    if(x==0 || x==1||n==0)
        return 1;
    if(n==1)
        return x;
    if(n%2==0)
        return (power(((x%mod)*(x%mod))%mod,n/2)%mod);
    else
        return ((x%mod)*(power(x,n-1)%mod)%mod);
}

int main()
{
    ll n;
    cin>>n;
    if(n>=30)
        cout<<"Yes";
    else cout<<"No";
 
}