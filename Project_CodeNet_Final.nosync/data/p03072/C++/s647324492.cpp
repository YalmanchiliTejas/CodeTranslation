#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define repone(i,n) for(int i=1;i<(int)(n);++i)

#define Rep(i,n) for(int i=0;i<(int)(n);++i)

#define int long long

using namespace std;

signed main()
{
    int x,y,z,w,i,j=1;
    cin>>x;
    std::vector<int> v(x);
    rep(i,x){
          cin >> v[i];
    }
    z=v[0];
    repone(i,x){

      if(v[i]>=z){
    j++;
    z=v[i];
      }
    }


    cout<<j<<endl;
    return 0;
}
