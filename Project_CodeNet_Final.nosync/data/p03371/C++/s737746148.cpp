#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<tuple>
#include<string.h>
#include<iomanip>
#include<stack>
#include<queue>
#include<map>
#include<deque>

using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define ALLOF(c) (c).begin(), (c).end()
#define Pa pair<ll,ll>
const ll mod=1000000007;
const ll INF=10e12;
const ll inf=-1;
ll ABS(ll a){return max(a,-a);}


int main(void){
    ll A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    ll money=A*X+B*Y;
    ll mi=min(X,Y);
    ll money2=A*(X-mi)+B*(Y-mi)+2*C*mi;
    ll ma=max(X,Y);
    ll money3=2*C*ma;
    cout<<min(min(money,money2),money3)<<endl;
    return 0;
}
