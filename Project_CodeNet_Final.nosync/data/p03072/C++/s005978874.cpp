#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 int N;
 cin>>N;
 vector<int>H(N);
 for(int i=0;i<N;i++){
     cin>>H[i];
 }
 int count=0;
 for(int i=0;i<N;i++){
    bool ok=true;
    for(int j=0;j<=i;j++){
        if(H[i]<H[j]){ok=false;}
    }
    if(ok){count++;}
 }
 cout<<count<<endl;
 return 0;}