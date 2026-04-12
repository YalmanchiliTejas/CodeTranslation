#include <iostream>
  #include <complex>
  #include <vector>
  #include <string>
  #include <algorithm>
  #include <cstdio>
  #include <numeric>
  #include <cstring>
  #include <ctime>
  #include <cstdlib>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <unordered_set>
  #include <list>
  #include <cmath>
  #include <bitset>
  #include <cassert>
  #include <queue>
  #include <stack>
  #include <deque>
 #include <iomanip>
#include <fstream>
 
  using namespace std;
   
 
//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

  typedef long long ll;
  typedef long double lld;
  typedef unsigned long long ull;
  // ll INF = INT_MAX;
  // ll mod = 1000000007;
  // lld PI = 3.141592653;
 
// const int N = 2e5 + 5;


  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      // ifstream cin("input.txt");

      string s;
      cin>>s;
      int k;
      cin>>k;
      int f = s[0] - '0';

       int n = s.length();
       if (n<k){
        cout<<"0\n";
        return 0;
       }
      if (k==1){
     
        ll ans = 9*(n-1) + f;
        cout<<ans<<"\n";
      }else if (k==2){
        ll ans = (n-2)*(n-1)*81/2;
        // cout<<ans<<endl;
        ans+= (f-1)*9*(n-1);
        // cout<<ans<<endl;
        int ss = 1;
        while (ss<n && s[ss]== '0') ss++;
        // cout<<ss<<" "<<s[ss]<<endl;
        // if (n>=2){
        //   ans+=s[1]-'0';
        // }
        if (ss<n) ans+= s[ss]-'0';
        // cout<<ans<<endl;
        // cout<<s[ss]<<endl;
        // cout<<"-";

        // cout<<ss<<endl;
        for (int i = ss+1;i<n;i++){
         
          ans+= 9;
          // cout<<ans<<endl;
          // cout<<i<<" "<<endl;
        }
        cout<<ans<<"\n";
      }else{

        ll ans = (n-3)*(n-2)*(n-1)*9*9*9/6;
        // cout<<ans<<endl;
        ans+= (f-1)*(n-1)*(n-2)*81/2;

        // cout<<(f-1)*(n-1)*(n-2)*81/2<<endl;
        int ss = 1;
        while (ss<n && s[ss]=='0') ss++;
        if (ss<n) ans+= (n-1-ss)*(n-2-ss)*81/2;
        // cout<<ans<<endl;
        // ans+= (n-2)*(n-3)*81/2;
          // int sec = s[1] -'0';
        
         if (ss<n) ans+= (s[ss]-'0'-1)*9*(n-1-ss);
       
        
          // ans+= s[ss] -'0';
          int sss = ss+1;
          while(sss<n && s[sss]=='0') sss++;
         if (sss<n) ans+= s[sss]-'0';
         // cout<<ans<<endl;
          for (int i = sss+1;i<n;i++) ans+=9;
        
      cout<<ans<<"\n";
      // cout<<n<<endl;

      }

}