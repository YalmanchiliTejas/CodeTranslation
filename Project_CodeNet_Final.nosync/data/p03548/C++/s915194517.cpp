#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
int main(){
  ios::sync_with_stdio(0);  cin.tie(0); cout<<setprecision(3); cout<<fixed;
  #ifdef DEBUG
  freopen("ip.txt","r",stdin);
  clock_t tStart = clock();
  #endif


  int x,y,z; cin>>x>>y>>z;
  cout<<(x-z)/(y+z);


  #ifdef DEBUG
	cout<<"\nExecution time: "<<(((double)clock() - tStart)/CLOCKS_PER_SEC)<<"s.\n";
	#endif
  return 0;
}
