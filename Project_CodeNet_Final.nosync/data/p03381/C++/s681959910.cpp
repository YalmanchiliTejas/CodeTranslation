#include <bits/stdc++.h>
using namespace std;
	
int main(){
  int i,j;
  int N;
  cin>>N;
  int a[N],b[N];
  for(i=0;i<N;i++) {
	cin>>a[i];
	b[i]=a[i];
  }
  sort(a,a+N);
	int p=a[N/2];
  for(i=0;i<N;i++){
	if(b[i]>=p) cout<<a[N/2-1]<<endl;
	else cout<<p<<endl;
  }
  return 0;
}
