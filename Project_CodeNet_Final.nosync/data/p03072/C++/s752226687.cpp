#include <bits/stdc++.h> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i,a,b,x;
    cin>>n;
    int arr[n],brr[n];
    i=0,a=1;
    while(i<n) {
      cin>>arr[i];
      brr[i]=arr[i];
      i++;
    }
    i=n-1;
    sort(arr,arr+n);
    b=arr[n-1];
    while(b!=brr[i])
      i--;
    n=i+1;
    i=1,x=brr[0];
    while(i<n) {
      if(brr[i]>=x) {
        a++;
        x=brr[i];
      }
      i++;
    }
    cout<<a<<endl;
    return 0;
}
