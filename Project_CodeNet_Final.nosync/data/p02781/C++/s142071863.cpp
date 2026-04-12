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

int main() {
    string n; cin>>n;
    int k,N=n.size(); cin>>k;
    vector<vector<int>> o(N,vector<int>(4,0)),x(N,vector<int>(4,0));
    o[0][0]=0; o[0][1]=1; x[0][0]=1; x[0][1]=n[0]-'0'-1;
    for(int i=1;i<N;i++){
        if(n[i]-'0'==0){
            rep(j,4) o[i][j]=o[i-1][j];
            x[i][0]=x[i-1][0];
            for(int j=1;j<=3;j++) x[i][j]=x[i-1][j]+9*x[i-1][j-1];
        }
        else{
            for(int j=1;j<=3;j++) o[i][j]=o[i-1][j-1];
            x[i][0]=x[i-1][0];
            for(int j=1;j<=3;j++) 
            x[i][j]=x[i-1][j]+9*x[i-1][j-1]+o[i-1][j]+(n[i]-'0'-1)*o[i-1][j-1];
        }
        
    }
    cout<<o[N-1][k]+x[N-1][k]<<endl;
}