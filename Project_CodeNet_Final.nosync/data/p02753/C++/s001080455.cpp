#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;
#define pb push_back
#define pii pair<ll,ll>
#define pi pair<int ,int> 
#define REP(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i-- )


int main()

{  
    
    string s;
    cin>>s;int count=0;
    for(int i=0;i<3;i++){if(s[i]=='A'){count++;}}
    
    if(s[0]==s[1] && s[2]==s[1]){cout<<"No";}
    else{cout<<"Yes";}
    return 0;
}