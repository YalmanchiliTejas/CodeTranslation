/*
गिरते हैं शहसवार ही मैदान-ए-जंग में ।
वो तिफ़्ल क्या गिरे जो घुटनों के बल चले ।।
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define int     long long int
#define ull     unsigned int
#define ld      long double
#define pb      push_back
#define pa      pair<int,int>
#define ppa     pair<pair<int,int>,int>
#define pap     pair<int,pair<int,int>>
#define v1d     vector<int>
#define v2d     vector<vector<int> >
#define vpa     vector<pair<int,int>>
#define M       1000000007
#define MN      LLONG_MIN
#define MX      LLONG_MAX
#define ff      first
#define ss      second
#define endl    "\n"
#define v1s     vector<string>
#define all(v)  v.begin(),v.end()
#define S(v)    sort(v.begin(),v.end())
#define RS(v)   sort(v.rbegin(),v.rend())
#define R(v)    reverse(v.begin(),v.end())
#define mxpq(T)    priority_queue <T>
#define mnpq(T)    priority_queue<T,vector<T>,greater<T>>
#define T       int tc;cin>>tc;while(tc--)
#define p2d(v)     for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define p1d(v)      for(auto a:v)cout<<a<<" ";cout<<endl;
#define ppd(v)      for(auto a:v)cout<<a.ff<<" "<<a.ss<<endl;
#define sz(v)       (int)(v.size())
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
#define qqq 400005


void Weapons19(){
    int n;cin>>n;
    v1d v(n);
    int a1=0,a2=0,ans;
    for(int i=0;i<n;i++){cin>>v[i];}
    for(int i=0;i<n;i++){
        if(i&1)a2+=v[i];
        else a1+=v[i];
    }
    v1d a(n),b(n);
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(i&1){x+=v[i];a[i]=max(x,y);}
            else {y+=v[i];a[i]=y;}
        }
        x=0,y=0;
        for(int i=n-1;i>=0;i--){
            if(i%2==0){x+=v[i];b[i]=max(x,y);}
            else {y+=v[i];b[i]=y;}
        }
    if(n%2==0){
        ans=max(a1,a2); 
        
        for(int i=1;i<n;i+=2){
            if((i+1)!=n){
                ans=max(ans,a[i-1]+b[i+2]);
            }
        }
        cout<<ans;return;
    }
    ans=a2;
    for(int i=0;i<n;i+=2){
        ans=max(ans,a1-v[i]);
    }
    // v1d a(n),b(n);
    for(int i=0;i<n;i++){
        int p=0;
        if(i>0)p+=a[i-1];
        if(i+2<n)p+=b[i+2];
        ans=max(ans,p);
    }
    v1d z(n);z[n-1]=v[n-1];
    v1d q(n);q[n-2]=-999999999999999;
    for(int i=n-3;i>=0;i--){
        if(i%2==0)
        z[i]=z[i+2]+v[i];
        if(i%2==1){
            q[i]=v[i]+max(q[i+2],z[i+3]);
            // cout<<i<<" "<<v[i]<<" "<<q[i]<<endl;
        }
    }
    // p1d(q)
    // cout<<ans;
    int w=0;
    for(int i=0;i<n;i+=2){
        w+=v[i];
        if(i+3<n)
        ans=max(ans,w+q[i+3]);
    }
    cout<<ans;











}

int32_t main(){

    /*
    त्यक्तवाधर्मं च लोभं च
    मोहंचो द्यमास्थिता।
    युद्ध्यध्वमनहंकारा
    यतो धर्मस्ततो जयः।।
    */

    cout<<fixed<<setprecision(16);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    

    Weapons19();
    
}
