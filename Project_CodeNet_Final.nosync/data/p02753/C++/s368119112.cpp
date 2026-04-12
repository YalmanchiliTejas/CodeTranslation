#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define N 200100
#define MOD 1000000007
#define fn(i,n) for(int i=0;i<n;i+=1)
#define rep(i,l,r) for(int i=l;i<=r;i+=1)
#define INF 100000000000000
#define pii pair<int,int>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int power(int x,int y){
    int res=1LL;
    while(y){
        if(y&1){
            res=(res*x)%MOD;
        }
        x=(x*x)%MOD;
        y=(y>>1);
    }
    return res;
}

signed main()
{
    
    speed
    string s;cin>>s;
    int n=s.size();
    int cnt[2]={0};
    for(int i=0;i<n;i+=1){
        cnt[s[i]-'A']+=1;
    }
    if(cnt[0]>=1 && cnt[1]>=1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    

    
    
    
    return 0;
}