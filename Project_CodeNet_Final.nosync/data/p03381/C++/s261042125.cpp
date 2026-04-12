#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=10000;
const ll INF=1000000000;
const int MAX=100001;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    int n;
    cin>>n;
    int a[200010];
    int b[200010];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        if(a[i]>b[n/2-1]){
            cout<<b[n/2-1]<<endl;
        }else{
            cout<<b[n/2]<<endl;
        }
    }
    return 0;
}