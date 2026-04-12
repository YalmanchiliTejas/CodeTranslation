#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair
#define mod 1000000007

using namespace std;

bool v[100100];
int del[100100];
int main()  {
    ll n,k;
    cin>>n>>k;
    ll res =0;

    int i =0 ;

    for(ll b=k+1 ;b <=n ;b ++){
        ll r1 =0 ;
        ll en= -1;
        for(ll j=k ; j<=n ;j+=b){
            if(en >= j){
                r1 += max(min(j+i,n) - max(en,0LL),0LL);
            }
            else
                r1 += min(j+i,n) - max(j,1LL)+1;
            en = j+i;
        }
        i++;
        res += r1;
    }
    cout<<res<<endl;
    return 0;
}
