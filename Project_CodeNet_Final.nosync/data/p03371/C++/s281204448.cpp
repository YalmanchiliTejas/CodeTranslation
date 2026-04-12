/**
 *    SATAR ALLAH
 *
**/
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main()
{

    long long A,B,C,X,Y;

     cin>>A>>B>>C>>X>>Y;

     long long  ans=100000000000000000;
     for(int i=0;i<=X;i++){

          ans=min(ans, (X-i)*A + 2*i*C + (Y-i)*B*(Y>i)  );
     }

      for(int i=0;i<=Y;i++){

          ans=min(ans, (Y-i)*B + 2*i*C + (X-i)*A*(X>i)  );
     }


     cout<<ans;

    return 0;
}
