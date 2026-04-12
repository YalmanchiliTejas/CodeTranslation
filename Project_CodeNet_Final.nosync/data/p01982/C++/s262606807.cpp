#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int n,l,r;
int a[60];
bool uru(int x){
    for(int i=0;i<n;i++){
        if((i)%2!=0 && x%a[i]==0){
            return false;
        }
        if((i)%2==0 && x%a[i]==0){
            return true;
        }
    }
    if(n%2==0) return true;
    else return false;
}
int main(){
    while(1){
        cin>>n>>l>>r;
        int cnt=0;
        if(n==0 && l==0 && r==0) break;
        for(int j = 0;j < n; j++){
            cin>>a[j];
        }
        for(int i = l;i <=r ; i++){
            if(uru(i)) {
                //cout<<i<<endl;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
