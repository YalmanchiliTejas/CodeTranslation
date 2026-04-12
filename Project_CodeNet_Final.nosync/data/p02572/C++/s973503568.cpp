#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define bug cout<<"BUG"
#define MAX 1000000007
#define nln cout<<"\n"
#define File_Input freopen("input.txt", "r", stdin)
#define File_Output freopen("output.txt", "w", stdout);
//bool mp[64000001];

int main(){
    fastio;
    ll t, ans;
    cin>>t;

    ll a[t+1], c[t+1] = {0};
    for(ll i=1; i<=t; i++){
      cin>>a[i];
      c[i] = c[i-1]+a[i];
    }
    ll x = a[1]%MAX * a[2]%MAX;
    x  = x%MAX;
    ans = x;
    for(ll i=3; i<=t; i++){
      ll temp = c[i-2]%MAX * abs(a[i]-a[i-1])%MAX;
      temp = temp%MAX;

      if(a[i]>a[i-1]){
        x = x + temp;
        x = x%MAX;
      }else{ //if(a[i]<a[i-1]){
        x = x - temp + MAX;
        x = x%MAX;
      }
      ll z = a[i]%MAX * a[i-1]%MAX;
      z = z%MAX;
      x += z;
      x = x%MAX;
      ans += x;
      ans = ans%MAX;


    }

    cout<<ans;

}
























