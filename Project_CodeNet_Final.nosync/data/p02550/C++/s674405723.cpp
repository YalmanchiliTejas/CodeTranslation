#include <bits/stdc++.h>
using namespace std;
#define   ll long long int
#define maxn 1000000
vector<ll> dp(maxn,0);
ll mod=998244353;

int main(){

ll n,x,m;
cin>>n>>x>>m;
ll sum=0;
ll last=x;
int tm=0;
int vis[m]={0};
int flag=0;
for(int i=0;i>=0;i++){
        if(vis[last]){
            tm=i;
            break;
        }
    vis[last]=1;
    sum+=last;
    last=last*last;
    last=last%m;
    //cout<<last<<endl;
}

ll tlast=x;
ll fans=0;
///cout<<last<<" "<<tlast<<endl;
for(int i=0;i>=0;i++){
    if(tlast==last || n==0 ){
        break;
    }
    fans+=tlast;
    sum-=tlast;
    tlast=tlast*tlast;
    tlast=tlast%m;
    tm--;
    n--;
}
//cout<<fans<<endl;
fans+= sum*(n/tm);
int lt=n%tm;
for(int i=0;i<lt;i++){
    fans+=last;
    last=(last*last)%m;
}
cout<<fans<<endl;



}
