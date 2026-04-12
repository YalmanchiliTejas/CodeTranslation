#include <bits/stdc++.h>


using namespace std;


#define ll long long
#define mk make_pair
#define pb push_back
#define ff first
#define sc second
#define all(x) x.begin(), x.end()
#define sz(x) (x).size()

ll gcd(ll a, ll b){
   if(b == 0) return a;
   
   return gcd(b, a % b);
}

ll sum(int n){
   if(n == 0){
      return n;
   }else{
      return sum(n/10) + n%10;
   }
}

int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   
   int a,b,c;cin>>a>>b>>c;
   string s=to_string(a)+to_string(b)+to_string(c);
   int n=stoi(s);
   if(n%4==0){
      cout << "YES";
   }else{
      cout << "NO";
   }
   return 0;
}
