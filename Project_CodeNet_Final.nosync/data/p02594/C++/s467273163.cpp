#include <bits/stdc++.h>

using namespace std;

int solve(){
    int n;
    cin>>n;
    if(n>=30) cout<<"Yes";
    else cout<<"No";
    return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cerr<<fixed<<setprecision(10);
  auto start = chrono::high_resolution_clock::now();
  int t=1;
  //cin>>t;
  while(t--)
    solve(),cout<<"\n";

  auto stop = chrono::high_resolution_clock::now(); 
  auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start); 
  //cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s \n";      
  
  return 0;
}
