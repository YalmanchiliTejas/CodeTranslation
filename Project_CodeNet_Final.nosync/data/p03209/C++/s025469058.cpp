#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(n);(i)++)
#define repr(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define forin(i,array) for(auto& x:array)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mod 1000000007
#define inf 10000000000000


typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
typedef vector<pint> vpint;

vll buglevel(50);
vll patty(50);

ll bug(ll level,ll down){
    if(level==0 && down==1)return 1;
    else if(down<=1)return 0;
    else if(1<down && down<=1+buglevel[level-1])return bug(level-1,down-1);
    else if(down==2+buglevel[level-1])return patty[level-1]+1;
    else if(2+buglevel[level-1]<down && down<=2+2*buglevel[level-1]){
        return 1+patty[level-1]+bug(level-1,down-2-buglevel[level-1]);
    }
    else return 2*patty[level-1]+1;
}

int main(){
    ll n,x;
    cin>>n>>x;
    buglevel[0]=1;patty[0]=1;
    rep(i,n)buglevel[i+1]=2*buglevel[i]+3;
    rep(i,n)patty[i+1]=2*patty[i]+1;
    cout<<bug(n,x)<<endl;
    return 0;
}