#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
 long long a,b,c,d,e,i,j;
 cin >> a;
 long long sum=0;
 vector<long long>vec;
 while(a--)
 {
     cin >> b;
     sum+=b;
     vec.push_back(b);
 }
 long long mul=0,cnt=1;
 for(i=0;i<vec.size()-1;i++)
 {
     cnt=1;
     sum-=vec[i];
     cnt=1;
     cnt=((vec[i]%mod)*(sum%mod))%mod;
     mul=((mul%mod)+(cnt%mod))%mod;



 }
 cout << mul << endl;
}
