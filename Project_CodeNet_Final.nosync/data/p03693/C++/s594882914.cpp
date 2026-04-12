    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <map>
    using namespace std;
    typedef long long ll;
    #define rep(i,n) for (int i=0;i < (int)(n);i++)

    int main(){
       int a,b,c;
      cin >> a >> b >> c;
      int ans;
      ans=a*100+10*b+c;
      if (ans%4 == 0) cout << "YES" << endl;
      else cout << "NO" << endl;

      
      return 0;
    }
      
      