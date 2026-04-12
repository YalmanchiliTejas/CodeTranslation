#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();

    int n;
    cin>> n;

    ll s[n], a[n], sum= 0;

    cin>> a[0];
    s[0]= a[0];
    for(int i=1; i<n; i++)
    {
        cin>> a[i];
        s[i]= (a[i] % MOD+ s[i-1]% MOD) % MOD;
    }

    for(int i= n-1; i>0; i--)
        sum += (((a[i] % MOD)* (s[i-1] % MOD) )% MOD);

    cout << sum % MOD << '\n';

    return 0;
}


