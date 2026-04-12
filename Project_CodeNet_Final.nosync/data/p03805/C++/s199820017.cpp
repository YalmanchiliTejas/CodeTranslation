#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include<algorithm> 
#include <iomanip>
#include <math.h>
#include <iostream>
#include <bitset>

#define db double
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define maxn 5005
#define mod 998244353
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define vv(z,a,b) vector<vector<int>>z(a,vector<int>(b))
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(c) begin(c),end(c)
#define pp pair<int,int>
#define fix(n) fixed << setprecision(n)
using namespace std;


int main(){
int n,m;cin>>n>>m;
vi d(n);
rep(i,n)d.at(i)=i+1;
vv (a,m,2);
rep(i,m)rep(j,2)cin>>a.at(i).at(j);
int ans=0;
do{
    if(d.at(0)!=1)break;
    int flag=0;
    for(int i=1;i<n;i++){
        rep(j,m){
        if((d.at(i-1)==a.at(j).at(0))||(d.at(i-1)==a.at(j).at(1))){
            if((d.at(i)==a.at(j).at(1))||(d.at(i)==a.at(j).at(0))){
                flag++;
                break;
            }
        }
    }
    }
    if(flag==(n-1)){
        if(flag<=m)ans++;
    }
}while(next_permutation(all(d)));
cout<<ans<<endl;
}