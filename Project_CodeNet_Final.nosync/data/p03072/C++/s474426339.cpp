#include <bits/stdc++.h>
#define ll long long //10^18
#define ull unsigned long long //10^19
using namespace std;
int main() {
  //ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  int maxi=arr[0],ans=0;
  for(int i=0;i<n;i++){
    if(arr[i]>=maxi){
      ans++;
      maxi=arr[i];
    }
  }
  cout<<ans;
  return 0;
}