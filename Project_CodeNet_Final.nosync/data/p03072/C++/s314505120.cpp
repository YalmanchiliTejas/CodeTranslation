#include <bits/stdc++.h>
using namespace std;

int main() {
int N,ans=1,anse=0;
cin>>N;
int H[N+1];
for(int i=1;i<=N;i++){
cin>>H[i];
}
for(int k=2;k<=N;k++){
  anse=0;
  if(H[k]>=H[1]){
    for(int d=1;d<k;d++){
      if(H[d]<=H[k]) {
        anse++;
    }
    if(anse==k-1)ans++;
    }
  }
}
cout<<ans<<endl;

}
