#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
  int n,count=1;
  cin>>n;
  vector<int> h(n);
  rep(i,n)
  {
    cin>>h[i];
  }
  for (int i = 1; i < n; i++)
  {
    bool flag=false;
    for(int j=0;j<=i;j++)
    {
      if(h[i]<h[j])
      {
        flag=true;
        break;
      }
    }
    if(flag)continue;
    else count++;
  }
  cout<<count<<endl;

  return 0;
}
