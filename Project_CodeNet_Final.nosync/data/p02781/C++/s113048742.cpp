//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string n; cin>>n;
    int N=n.size();
    int k; cin>>k;
    vector<vector<int>> dpv(N,vector<int>(k+1,0)),dpi(N,vector<int>(k+1,0));
    dpv[0][1]=1; dpi[0][1]=n[0]-'0'-1; dpi[0][0]=1;
    for(int i=1;i<N;i++){
        if(n[i]=='0'){
            rep(j,k+1){
                dpv[i][j]=dpv[i-1][j];
                if(j==0){
                    dpi[i][0]=dpi[i-1][0];
                    continue;
                }
                dpi[i][j]=dpi[i-1][j-1]*9+dpi[i-1][j];
            }
        }
        else{
            rep(j,k+1){
                if(j==0){
                    dpi[i][0]=dpi[i-1][0];
                    continue;
                }
                dpv[i][j]=dpv[i-1][j-1];
                dpi[i][j]=dpi[i-1][j]+dpi[i-1][j-1]*9;
                dpi[i][j]+=dpv[i-1][j-1]*(n[i]-'0'-1)+dpv[i-1][j];
            }
        }
    }
    cout<<dpi.back()[k]+dpv.back()[k]<<endl;
}