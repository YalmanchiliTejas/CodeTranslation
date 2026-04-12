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

int n;
vint vec(200);
int heigth=-10;
int counter=0;

int main(){
    cin>>n;
    rep(i,n)cin>>vec[i];
    rep(i,n){
        if(vec[i]>=heigth)counter++;
        heigth=max(heigth,vec[i]);
    }
    cout<<counter<<endl;
}