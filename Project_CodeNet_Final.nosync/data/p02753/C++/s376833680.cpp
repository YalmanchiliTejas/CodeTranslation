#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
vector<vector<int> > d; 
ll power(ll a,int n){
  if(n==0)
    return 1;
  if((n%2)==0)
    return (power((a*a)%mod,n/2))%mod;
  else
    return (a*(power((a*a)%mod,n/2))%mod)%mod;    
}
double sqrt1(double a){
    double l=0;
    double h=a;
    double m;
    double ans;
    while((h-l)>=1e-8){
       m=(h+l)/2;
       if((m*m)<a){
             ans=m;
             l=m;
       }
       else if(m*m==a){
             ans=m;
             break;
       }
       else{
          h=m;
       }
    }
    return ans;
}
int main(){
FASTIO
string s;
cin>>s;
int a=0;
int b=0;
for(int i=0;i<s.size();i++){
  if(s[i]=='A')
    a++;
  else
    b++;
}
if((a>0)&&(b>0)){
    cout<<"Yes";
}
else
   cout<<"No";
return 0;
}