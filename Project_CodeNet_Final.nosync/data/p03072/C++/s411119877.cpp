#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  cin>>n;
  int arr[n];
  for(int i =0; i < n; i++){
  	cin>>arr[i];
  }
  int co = 1;
  int ma = arr[0];
  for(int i =1; i < n; i++){
	ma = max(arr[i],ma);
	if(arr[i] >= ma) co++;
    }
  cout<<co<<"\n";
}