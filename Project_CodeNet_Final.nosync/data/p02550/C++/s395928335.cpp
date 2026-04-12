#include<bits/stdc++.h>
using namespace std;
#define INIT  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define ll long long
#define pii pair<int, int>
#define count_bits __builtin_popcount
#define int ll

int n, x, m;
bool v[100010];
int ind[100010];
int p[100010];


int32_t main(){
INIT
//cout<<totient(9)<<flush;
cin>>n>>x>>m;
if(m==1){
    cout<<x; return 0;
}
int res=0;
int a=x;

for(int i=1; i<=m; i++){
    if(v[a]==true){
        res+=a;
        int sum=res-p[ind[a]]; sum*=( (n-ind[a])/(i-ind[a]) ); sum+=p[ind[a] ];
        //cout<<a<<"\n";
         int b=a; a*=a; a%=m;
         for(int j=1; j<=((n-ind[b])%(i-ind[b]));j++ ){sum+=a; a*=a; a%=m;   }
          //cout<<((n-ind[a])%(i-ind[a]))<<"\n";
            cout<<sum; return 0;
    }
    v[a]=true; ind[a]=i;
    res+=a; a*=a; a%=m;
    p[i]=res;
    if(i>=n){ cout<<res; return 0; }
}


return 0;
}



