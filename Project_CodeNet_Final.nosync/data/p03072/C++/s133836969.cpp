#include <bits/stdc++.h>

#define INF 1000000000
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {

    int N,maxtmp=0,cnt=0;
    cin >> N;
    vector<int>A(N);
    for (int i = 0; i < N; i++) { 
      cin >> A[i];
      if(maxtmp<=A[i])cnt++;
      if(maxtmp<A[i])maxtmp=A[i]; }
    
  
    cout<<cnt<<endl;
}
    

