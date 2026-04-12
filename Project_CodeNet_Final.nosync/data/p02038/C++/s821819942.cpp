#include <bits/stdc++.h>
#define int long long
using namespace std;

int N;
char p[100005];

signed main(){
  
  cin>>N;
  
  for(int i=0;i<N;i++) cin>>p[i];
  
  char pp = p[0];
  
  for(int i=1;i<N;i++){
    
    if( pp == 'T' && p[i] == 'T' ) pp = 'T';
    else if( pp == 'T' && p[i] == 'F' ) pp = 'F';
    else if( pp == 'F' && p[i] == 'T' ) pp = 'T';
    else if( pp == 'F' && p[i] == 'F' ) pp = 'T';
    
  }

  cout<<pp<<endl;
  
  return 0;
}

