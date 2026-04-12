#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
   int n,k;
   string s;
   cin >> n>> s >> k;
   char x=s.at(k-1);
   vector<char> ans(n);
   rep(i,n){
       if(s.at(i)==x)ans.at(i)=x;
       else ans.at(i)='*';
   }
   rep(i,n)cout << ans.at(i);
   cout << endl;
}