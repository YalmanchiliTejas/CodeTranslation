#include <iostream>
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii std::pair<int,int>
#define pli std::pair<ll,int>
#define pil std::pair<int,ll>
#define psi std::pair<string,int>
#define pll std::pair<ll,ll>
#define pci std::pair<char,int>
#define sll(x) scanf("%lld",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define pb push_back
#define vll std::vector<ll>
#define vpi std::vector<std::pair<int,int>>
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define vvpil std::vector<std::vector<std::pair<int,ll>>>
#define vlpii std::vector<std::list<pii>>
#define vlpil std::vector<std::list<pil>>
#define li std::list<int>
#define lpil std::list<pil>
#define Endl printf("\n")
#define vli vector<list<int>>
#define vvll vector<vector<ll>>
#define mp make_pair
#define ma 100000000
#define mod 1000000007
const ll  INF=10000000000000;
using namespace std;
ll optimalStrategyOfGame(ll arr[],int n){
    ll table[n][n];
    for(int gap=0;gap<n;++gap){
        for(int i=0,j=gap;j<n;++i,++j){
            ll x=((i+2)<=j?table[i+2][j]:0);
            ll y=((i+1)<=j-1?table[i+1][j-1]:0);
            ll z=(i<=(j-2)?table[i][j-2]:0);
            table[i][j]=max(arr[i]+min(x,y),arr[j]+min(y,z));

        }
    }
    return table[0][n-1];

}
int main()
{
    IOS;
    int n;cin>>n;
    ll a[n];
    ll sum=0;
    for(int i=0;i<n;i++) {cin>>a[i];sum+=a[i];}
    cout<<2*optimalStrategyOfGame(a,n)-sum;
    return 0;
}
