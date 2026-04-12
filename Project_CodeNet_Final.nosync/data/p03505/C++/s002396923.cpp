#include <iostream>
#include<algorithm>
#include<iomanip>
#include<string.h>
#include<set>
#include<map>
#include<cmath>
#include<vector>
#include<iomanip>
#include<queue>
using namespace std;
#define inf e18
#define x first
//#define y second
#define ll long long
#define ii pair<ll, ll>
#define vi vector<ll>
#define vii vector<ii>
#define pb push_back
#include<stack>
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll a, b, c;
ll n, k;

int main()
{
    ios
    ll i, j,m;
    cin>>n>>a>>b;
    if(n<=a){
        cout<<1;
        return 0;
    }
    if(b>=a){
        cout<<-1;
        return 0;
    }
    cout<<1+2*((n-a+(a-b-1))/ (a-b));
}
