#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t,x,y,m,q;

int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>n>>x>>m;
      vector<ll>ans;
      map<ll,ll>ma;
      ma[x]=1;
      ll ind=0,sum=0;
      ans.push_back(x);
      for(int i=1;i<min(n,m);i++){
        ans.push_back((ans.back()*ans.back())%m);
        if(ma[ans.back()]){
          ind=ma[ans.back()];
          ans.pop_back();
          break;
        }
        else
          ma[ans.back()]=i+1;
      }
      ll pre[ans.size()+1]={0};
      for(int i=1;i<=ans.size();i++){
        pre[i]+=pre[i-1]+ans[i-1];
      }
      if(ans.back()==0){
        cout<<pre[ans.size()];
      }
      else if(ind!=0){
        sum=pre[ans.size()]-pre[ind-1];
        sum=((n-ind+1)/(ans.size()-ind+1))*sum;
        sum+=pre[ind-1];
        if((n-ind+1)%(ans.size()-ind+1))
          sum+=(pre[ind+(n-ind)%(ans.size()-ind+1)]-pre[ind-1]);
        cout<<sum;
      }
      else{
        cout<<pre[n];
      }
}