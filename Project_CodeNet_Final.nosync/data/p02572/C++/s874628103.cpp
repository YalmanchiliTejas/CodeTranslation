
#include<bits/stdc++.h>
#define   ll            long long int
#define   endl          "\n"
#define   vi            vector<int>
#define   vll           vector<ll>
#define   pb            push_back
#define   all(p)        p.begin(),p.end()
#define   F             first
#define   S             second
#define   mp            make_pair
#define   MOD           1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int t=1;
    while(t--){
       ll c_sum=0,sum=0,x=0,y;
       int n,a;
       cin>>n;
       vi v;

       for(int i=0;i<n;i++){
         cin>>a;
         v.pb(a);
         c_sum+=a;
         c_sum%=MOD;
       }

       for(int i=0;i<v.size();i++){
          c_sum-=v[i];
          if (c_sum < 0) c_sum += MOD;
          sum+=c_sum*v[i];
          sum%=MOD;
       }

       cout<<sum<<endl;
    }


return 0;
}



