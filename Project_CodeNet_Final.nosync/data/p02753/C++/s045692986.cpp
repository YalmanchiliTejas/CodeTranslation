/*BY-ADITYA OJHA
  LEARN DSA SINCERELY*/
#include <bits/stdc++.h>
#define ll long long int
#define forin for(int i=0;i<n;i++)
#define forjn for(int j=0;j<n;j++)
#define pb push_back
#define vx vector<ll> x
#define fas1  ios_base::sync_with_stdio(false)
#define fas2   cin.tie(NULL)
using namespace std;


int main()
{
     fas1;
     fas2;
     string s;
     cin>>s;
     ll flag=0;
     for(int i=0;i<s.size()-1;i++)
     {
         if(s[i]!=s[i+1])
         {
             flag=1;

         }
     }if(flag)cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
     return 0;

}
