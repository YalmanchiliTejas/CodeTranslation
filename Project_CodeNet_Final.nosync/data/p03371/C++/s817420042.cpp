
     #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9+7;
ll min(ll a,ll b){
  if(a>b){
    return b;
    }
      else{
        return a;
      }
  }

int main(){
  ll A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  
  if(A+B<=C*2){
    cout<<A*X+B*Y<<endl;
  }
  
  else{
   if(X>Y){
     cout<<min(Y*C*2+(X-Y)*A,X*C*2)<<endl;
  }
  
    else{
cout<<min(X*C*2+(Y-X)*B,Y*C*2)<<endl;
}
  }
}
    