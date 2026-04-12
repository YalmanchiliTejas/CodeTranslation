#include<iostream>
using namespace std;
int main()
{
  int l[12];
  int i,j;
  int ans=0;
  int count[12]={};
  for(i=0;i<12;i++){
    cin >> l[i];
  }
  for(i=0;i<12;i++){
    for(j=i+1;j<12;j++){
      if(l[i]==l[j]){
	count[i]++;
	count[j]++;
      }
    }
  }
  for(i=0;i<12;i++){
    if(count[i]==0) ans=1;
  }
  if(ans==0) cout << "yes\n";
  else cout << "no\n";
  return 0;
}