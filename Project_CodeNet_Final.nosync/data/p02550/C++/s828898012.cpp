#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x,m;

main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE    
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout); 
    #endif

    cin>>n>>x>>m;
    x%=m;
    vector<ll>a;
    map<ll,int>lookup;
    ll cycle=-1;
    for(int i=1;i<=min(n,m+5);i++){
        if(lookup[x]){
            cycle=x;
            break;
        }
        a.push_back(x);
        lookup[x]++;
        x*=x;x%=m;
    }

     ll sum=0;
    if(cycle==-1){
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        cout<<sum<<"\n";
        return 0;
    }

    int k=0,start;
    for(int i=0;i<n;i++){
        if(a[i]==cycle){
            start=i;
            break;
        }
        sum+=a[i];
        k++;
    }
    n-=k;
    
    ll cyclesum=0,len=0;
    for(int i=start;i<a.size();i++) cyclesum+=a[i],len++;
    sum+=(n/len)*cyclesum;
    n%=len;
    while(n--){
        sum+=a[start++];
    }
    cout<<sum<<"\n";
}       