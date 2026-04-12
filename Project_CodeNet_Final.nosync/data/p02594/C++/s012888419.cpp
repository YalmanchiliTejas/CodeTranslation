/******************
 *AUTHOR: speckrel*
 ******************/
 
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
//Function to read int array
void read(ll arr[], ll n){
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
}
 
void solve(){
    static int i=1;
    //cout<<"This is a test code "<<i<<"\n";
    i++;
}
 
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll temp;
  cin>>temp;
  if(temp>=30){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }
    return 0;
}