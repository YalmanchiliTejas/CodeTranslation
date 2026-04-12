#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
  int n;
  cin>>n;
  vector<int>a;
  for(int i=0;i<n;i++)
  {
       int x;
       cin>>x;
       a.push_back(x);
  }
  sort(a.begin(),a.end());
  deque<int> emni;
  emni.push_back(a[0]);
  int mi=1,ma=n-1;
  int r=1;
  while (emni.size()<n)
  {
    if (r&1)
    {
      int x=a[ma];
      int y=(ma-1<mi)? 0 : a[ma-1];
      ma-=2;

      int f=emni.front(),b=emni.back();

      int conf1=abs(x-f)+abs(y-b);
    int conf2=abs(x-b)+abs(y-f);

      if (conf1 > conf2)
      {
        emni.push_front(x),emni.push_back(y);
      }
      else
      {
        emni.push_front(y),emni.push_back(x);
      }
    }
    else
    {
      int x=a[mi];
      int y=(mi+1>ma)? 0 : a[mi+1];
      mi+=2;

      int f=emni.front(),b=emni.back();

      int conf1=abs(x-f)+abs(y-b);
      int conf2=abs(x-b)+abs(y-f);

      if (conf1 > conf2)
      {
        emni.push_front(x),emni.push_back(y);
      }
      else
      {
        emni.push_front(y),emni.push_back(x);
      }
    }
    r++;
  }
  vector<int>ans;
  for (int i : emni)
  {
    if (i)
      ans.push_back(i);
  }

  

  int val1=0;
  for(int i=0;i<n-1;i++)
    val1+=abs(ans[i]-ans[i+1]);
  

  emni.clear();

  emni.push_back(a[n-1]);
  ma=n-2,mi=0;
  r=1;
  while (emni.size()<n)
  {
    if (r&1)
    {
      int x=a[mi];
      int y=(mi+1>ma)? 0 : a[mi+1];
      mi+=2;

      int f=emni.front(),b=emni.back();

      int conf1=abs(x-f)+abs(y-b);
      int conf2=abs(x-b)+abs(y-f);

      if (conf1 > conf2)
      {
        emni.push_front(x),emni.push_back(y);
      }
      else
      {
        emni.push_front(y),emni.push_back(x);
      }
    }
    else
    {
      int x=a[ma];
    int y=(ma-1<mi)? 0 : a[ma-1];
      ma-=2;

      int f=emni.front(),b=emni.back();

      int conf1=abs(x-f)+abs(y-b);
      int conf2=abs(x-b)+abs(y-f);

      if (conf1 > conf2)
      {
        emni.push_front(x),emni.push_back(y);
      }
      else
      {
        emni.push_front(y),emni.push_back(x);
      }
    }
    r++;
  }
  ans.clear();
  for (int i : emni)
  {
    if (i)
      ans.push_back(i);
  }



  int val2=0;
  for(int i=0;i<n-1;i++)
    val2+=abs(ans[i]-ans[i+1]);


  cout<<max(val1,val2)<<"\n";
  return 0;
}