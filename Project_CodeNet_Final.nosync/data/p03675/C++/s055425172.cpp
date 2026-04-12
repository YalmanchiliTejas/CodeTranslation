#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n) REP(i,0,n)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    deque<int> b;
    rep(i,n){
        int tmp;cin>>tmp;
        if(i%2==0)b.push_front(tmp);
        else b.push_back(tmp);
    }
    if(n%2!=0)for(int i=0;i<n;i++)cout<<b[i]<<' ';
    else for(int i=n-1;i>=0;i--)cout<<b[i]<<' ';
    cout<<endl;
    return 0;
}
