#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int long long
typedef long long ll;
typedef pair<int,int> P;

ll ans=0;
ll num[52];
ll save[52];

void search(int n, int x){
    ll sum=num[n];
    if(n==0){
        ans++;
        return;
    }
    if(x==1) return;
    if(x==(sum+1)/2){
        ans+=save[n]+1;
        return;
    }
    if(x==sum){
        ans+=2*save[n]+1;
        return;
    }
    if(x<(sum+1)/2) search(n-1,x-1);
    else{
        ans+=save[n]+1;
        search(n-1,x-2-(num[n]-3)/2);
    }
}

signed main(){
    int n,x;
    cin >> n >> x;
    num[0]=1;
    for(int i=1;i<=50;i++){
        num[i]=num[i-1]*2+3;
    }

    save[0]=0;
    for(int i=1;i<=50;i++) save[i]=save[i-1]*2+1;

    search(n,x);

    cout << ans << endl;


}