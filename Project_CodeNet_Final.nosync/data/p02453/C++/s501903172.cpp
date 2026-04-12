#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n;
main()
{
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  int q;cin>>q;
  for(int i=0;i<q;i++)
  {
    int k;cin>>k;
    cout<<distance(a.begin(),lower_bound(a.begin(),a.end(),k))<<endl;
  }
}

