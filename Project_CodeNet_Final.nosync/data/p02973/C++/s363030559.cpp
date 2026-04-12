 #include<bits/stdc++.h>
#define mod 1000000007
#define fr first
#define se second
#define ll long long
#define PI 3.1415926535 
#define pb push_back
#define mpr make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define senky_bansal ios_base::sync_with_stdio(false);
#define IIIT_ALLAHABAD    cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector<ll>v[100005];
multiset<ll>st;
signed main()
{   
      senky_bansal
      IIIT_ALLAHABAD
      
      ll n;
      cin>>n;
      ll a[n];
      for(int i=1;i<=n;i++)
      {
          cin>>a[i];
      }
      int j=0;
      for(int i=1;i<=n;i++)
      {
          if(i==1)
          {
              v[0].pb(a[i]);
              j++;
              st.insert(a[i]);
          }
          else
          {
              auto it1 = st.lower_bound(a[i]);
              if(it1==st.begin())
              {
                  v[j].pb(a[i]);
                  j++;
                  st.insert(a[i]);
              }
              else
              {
                  it1--;
                  st.erase(it1);
                  st.insert(a[i]);
              }
          }
      }
      cout<<j<<endl;
    
    
}














