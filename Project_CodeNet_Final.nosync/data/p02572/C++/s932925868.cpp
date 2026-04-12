#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define m 1000000007
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}

int main() {
   fast();
   int n;
   cin>>n;
   long long a[n+1];
   long long b[n+1];
   a[0]=0;
   b[0]=0;
   for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=a[i]+b[i-1];
   }
   long long sum=0;
   for(int i=1;i<=n;i++){
     sum+=((a[i]%m)*((b[n]-b[i])%m))%m;
   }
   cout<<sum%m<<"\n";

}