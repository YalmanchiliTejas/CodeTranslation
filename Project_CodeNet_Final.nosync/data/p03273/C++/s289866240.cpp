#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define inf (long long int) 1e18
#define vl vector<ll> 
#define pll pair<ll, ll>
#define mll map<ll, ll> 
#define mod 1000000007
ll gcd(ll a,ll b);
ll palindrome(string s);
ll modexp(ll a,ll b,ll m);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll h,w;
    cin>>h>>w;
    char ch[h][w];
    char a[h][w];
    loop(i,0,h){
        loop(j,0,w){
            cin>>ch[i][j];
            a[i][j]=ch[i][j];
        }
    }

    loop(i,0,h){
        bool y=true;
        for(ll j=0;j<w&& y==true;j++){
            if(ch[i][j]!='.'){
                y=false;
            }
        }
        if(y==true){
            loop(j,0,w){
                a[i][j]='*';
            }
        }
    }
    loop(i,0,w){
        bool y=true;
        for(ll j=0;j<h && y==true;j++){
            if(ch[j][i]!='.'){
                y=false;
            }
        }
        if(y==true){
            loop(j,0,h){
                a[j][i]='*';
            }
        }
    }
    loop(i,0,h){
        bool p=false;
        loop(j,0,w){
            if(a[i][j]!='*'){
                cout<<a[i][j];
                p=true;
            }
        }
        if(p==true) cout<<endl;
    }

}

ll gcd(ll a, ll b){
    if (a == 0)   return b;
    if(b==0)      return a;
    if (a == b)   return a;
    if (a > b)    return gcd(a%b, b);
    return gcd(a, b%a);
}

ll palindrome(string s){
    ll l = 0;
    ll h = s.length() - 1;
    while (h > l){
        if (s[l++] != s[h--]){
            return 0;
        }
    }
    return 1;
}

ll modexp(ll a, ll b, ll m){
    if (b==0)
        return 1;
    ll temp = modexp(a,b/2,m);
    temp = (temp*temp)%m;
    if (b&1)
        return (temp*(a%m))%m; // if b is odd a^b = a^(b/2)*a^(b/2)*a
    return temp;
}