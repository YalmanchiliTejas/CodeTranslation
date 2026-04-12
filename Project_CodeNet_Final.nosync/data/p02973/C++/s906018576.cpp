#include<bits/stdc++.h>
#define REP(i,n) for(int (i)=0 ;(i)<(n);(i)++)
#define REPR(i,n) for(int (i)=(n);(i)>=0;(i)--)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(x) x.begin(),x.end()
#define REVERSE(x) reverse(x.begin(),x.end())
#define SORT(x,n) sort(x,x)
#define P pair<int,int>
typedef long long LL;
const int INF=1000000007;
using namespace std;
int gcd(int a,int b){
  if(a%b==0){return b;}
  else{return gcd(b,a%b);}
}

int main(){
int N;
cin>>N;
vector<int> a(N);
REP(i,N){
    cin>>a[i];
}
int ans=0;
for(int i=0;i<N;i++){
    if(a[i]!=-1){
        ans++;
        int index=i;
        int counter=i+1;
        while(index<N){
            while(a[index]>=a[counter]){
            counter++;
            }
          a[index]=-1;
          index=counter;
        }
}
}
cout<<ans;
}