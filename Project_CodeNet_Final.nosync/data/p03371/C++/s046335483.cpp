    #include <bits/stdc++.h>
     
    using namespace std;
    typedef long long ll;
    ll mod = 1e9+7;
     
    int main(void)
    {
      ll A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
      ll res;
      if(C*2>A+B){
        res=X*A+B*Y;
      }
      else{
        ll pat1=min(X,Y)*C*2;
        if(X>Y){
          pat1+=(X-Y)*A;
        }
        else if(Y>X){
          pat1+=(Y-X)*B;
        }
        
        ll pat2=max(X,Y)*C*2;
        
        res = min(pat1,pat2);
      }
      cout<<res<<endl;
    }