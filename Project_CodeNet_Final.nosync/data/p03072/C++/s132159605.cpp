#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
cin>>N;
vector<int>H(N);
for(int i=0;i<N;i++)cin>>H[i];
int r=H[0],cnt=0;
for(int i=0;i<N;i++){
    if(r<=H[i+1]){
    cnt++;
    r=H[i+1];
    }
}
cout<<cnt+1;
return 0;
}
