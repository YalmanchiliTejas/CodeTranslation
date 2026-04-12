/**
    @Author:Monk78
    @Topic:OptimalGameStrategy->D-p31(geeks)
        ->Both chooses maximum element optimally
**/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
//#define S second;
//#define F first;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define vpshVar() int main()

struct Game{
    ll F,S;
    ll pick=0;
};
Game vec[3020][3020];
void fxn(ll arr[],ll N){

    for(ll i=0;i<N;i++){
        vec[i][i].F=arr[i];
        vec[i][i].pick=i;
    }
    for(ll l=2;l<=N;l++){
        for(ll i=0;i<=N-l;i++){
            ll j=i+l-1;
            if(arr[i]+vec[i+1][j].S > vec[i][j-1].S+arr[j]){
                vec[i][j].F=arr[i]+vec[i+1][j].S;
                vec[i][j].S=vec[i+1][j].F;
                vec[i][j].pick=i;
            }
            else{
                vec[i][j].F=arr[j]+vec[i][j-1].S;
                vec[i][j].S=vec[i][j-1].F;
                vec[i][j].pick=j;
            }

        }
    }
}

vpshVar(){
       ll N,sum=0;
       sl(N);
       ll arr[N];
       for(ll i=0;i<N;i++){
            sl(arr[i]);
       }
       for(ll i=0;i<N+5;i++){
        for(ll j=0;j<N+5;j++){
            vec[i][j].F=vec[i][j].S=vec[i][j].pick=0;
        }
       }
       fxn(arr,N);
       cout<<vec[0][N-1].F-vec[0][N-1].S<<endl;
return 0;
}
