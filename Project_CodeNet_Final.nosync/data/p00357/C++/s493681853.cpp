#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=10000000;
const ll INF=1000000001;
const ll LINF=4000000000000000010;
const double EPS=1e-9;
int dx[5]={0,1,0,-1,0};
int dy[5]={1,0,-1,0,0};
int d[300010];
int ma[300010],mi[300010];
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
        d[i]/=10;
        if(i){
            ma[i]=max(ma[i-1],i+d[i]);
        }else{
            ma[i]=i+d[i];
        }
    }
    fill(mi,mi+n,INF);
    for(int i=n-1;i>=0;i--){
        if(i<n-1){
            mi[i]=min(mi[i+1],i-d[i]);
        }else{
            mi[i]=i-d[i];
        }
    }
    int pos=0;
    while(pos<n-1){
        if(pos==ma[pos]){
            cout<<"no"<<endl;
            return 0;
        }
        pos=ma[pos];
    }
    pos=n-1;
    while(pos>0){
        if(pos==mi[pos]){
            cout<<"no"<<endl;
            return 0;
        }
        pos=mi[pos];
    }
    cout<<"yes"<<endl;
}
