#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define SFOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define INF INT_MAX
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
int main(){
   cin.tie(0);
   ios::sync_with_stdio(false);
   int n,k;
   char s[1001];
   cin>>n>>s>>k;
   FOR(i,n){
     if(s[i]!=s[k-1]) s[i]='*';
   }
   cout<<s<<endl;
   return 0;
}
