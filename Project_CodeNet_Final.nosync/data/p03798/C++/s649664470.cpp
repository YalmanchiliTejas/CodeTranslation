#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

string s,ans="";

void f(ll i){
    if(ans[i]=='S'){
        if(s[i]=='o'){
            ans[i+1]=ans[i-1];
        }
        else{
            if(ans[i-1]=='S'){
                ans[i+1]='W';
            }
            else{
                ans[i+1]='S';
            }
        }
    }
    else if(ans[i]=='W'){
        if(s[i]=='x'){
            ans[i+1]=ans[i-1];
        }
        else{
            if(ans[i-1]=='S'){
                ans[i+1]='W';
            }
            else{
                ans[i+1]='S';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n>>s;
    int count=1;

    for(int i=0;i<=n;i++){
        ans+=" ";
    }
    ans[0]='S';
    ans[1]='S';
    for(int i=1;i<=n-1;i++){
        f(i);
    }
    if(s[0]=='o'){
        if(ans[n-1]=='W')
            count=0;
    }
    else if(s[0]=='x'){
        if(ans[n-1]=='S')
            count=0;
    }
    if(ans[n]!=ans[0]){
        count=0;
    }

    if(count==0){
        count=1;
        for(int i=0;i<=n;i++){
            ans[i]=' ';
        }
        ans[0]='S';
        ans[1]='W';
        for(int i=1;i<=n-1;i++){
            f(i);
        }
        if(s[0]=='o'){
            if(ans[n-1]=='S')
                count=0;
        }
        else if(s[0]=='x'){
            if(ans[n-1]=='W')
                count=0;
        }
        if(ans[n]!=ans[0]){
            count=0;
        }
    }

    if(count==0){
        count=1;
        for(int i=0;i<=n;i++){
            ans[i]=' ';
        }
        ans[0]='W';
        ans[1]='W';
        for(int i=1;i<=n-1;i++){
            f(i);
        }
        if(s[0]=='o'){
            if(ans[n-1]=='W')
                count=0;
        }
        else if(s[0]=='x'){
            if(ans[n-1]=='S')
                count=0;
        }
        if(ans[n]!=ans[0]){
            count=0;
        }
    }

    if(count==0){
        count=1;
        for(int i=0;i<=n;i++){
            ans[i]=' ';
        }
        ans[0]='W';
        ans[1]='S';
        for(int i=1;i<=n-1;i++){
            f(i);
        }
        if(s[0]=='o'){
            if(ans[n-1]=='S')
                count=0;
        }
        else if(s[0]=='x'){
            if(ans[n-1]=='W')
                count=0;
        }
        if(ans[n]!=ans[0]){
            count=0;
        }
    }
    if(count==0)
        cout<<-1<<endl;
    else{
        ans=ans.substr(0,n);
        cout<<ans<<endl;
    }
    return 0;
}
