#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define fs first
#define sc second
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<ll, ll> l_l;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

void solve(){
   int a,b,c,x,y;
   cin>>a>>b>>c>>x>>y;
   int maxp=max(x,y);
   int minp=min(x,y);
   int sum=0;
   for(int i=0;i<2*minp;i++){
       sum+=c;
   }
   if(maxp!=minp){
    for(int i=0;i<maxp-minp;i++){
            if(maxp==x)sum+=a;
            else sum+=b;
    }
 }
int suml=0;
rep(i,x)suml+=a;
rep(i,y)suml+=b;
int summ=0;
rep(i,2*maxp)summ+=c;
cout<<min(summ,min(sum,suml));
}

int main(){
    cout<<std::fixed<<std::setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}