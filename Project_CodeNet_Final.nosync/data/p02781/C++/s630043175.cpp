        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 1000001;
const int MOD = 1000000007;
   
        signed main() {
            string no;
         int n0,k,n;
         cin>>no>>k;
         reverse(no.begin(),no.end());
        int m=1,t=no.size()-1,ans=0,p;
        for(int i=k;i>0;i--){
           while(t>=0&&no[t]=='0')t--;
if(t<0)break;
           if(i==3){
               ans+=t*(t-1)*(t-2)*729/6;
              ans+=t*(t-1)*81*((long(no[t]-'0')-1) )/2;
        
           }
           if(i==2){
                 ans+=t*(t-1)*81/2;
               ans+=t*9*(long(no[t]-'0')-1);
           }
           if(i==1){
               ans+=t*9;
               ans+=((long(no[t]-'0')) );
           }

           t--;
        //   cerr<<n;
        }

        

        cout<<ans;

        }
