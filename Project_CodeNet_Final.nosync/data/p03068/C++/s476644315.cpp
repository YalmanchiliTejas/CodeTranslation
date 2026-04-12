#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(n);(i)++)
#define repr(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define all(v) (v).begin(),(v).end()
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define pb push_back
#define mod 1000000007
#define inf 1000000000
#define llinf 1000000000000000


typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
typedef vector<pint> vpint;

int n;

int main(){
    int n,k;
    string str;
    cin>>n>>str>>k;
    char s=str[k-1];
    rep(i,n){
        if(str[i]!=s)str[i]='*';
    }
    cout<<str<<endl;
}