#include <bits/stdc++.h>

using namespace std;
int main (){

   int N;
cin>>N;
int H[N];
for(int i=0;i<N;i++)
    cin>>H[i];
int cnt=1;
int r=H[0];
for(int i=1;i<N;i++){
    if(r<=H[i]){
    cnt++;
    r=H[i];
    }
}
cout<<cnt;
return 0;
}