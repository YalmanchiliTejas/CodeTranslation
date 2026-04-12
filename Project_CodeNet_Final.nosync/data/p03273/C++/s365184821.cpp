#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int main()
{
  //inter
  int h,w;
  cin>>h>>w;
  vector<string> a(h);
  for(int i=0;i<h;i++)
  {
    cin>>a[i];
  }

  //judgement of #
  vector<bool> row(h,false);
  vector<bool> col(w,false);
  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      if(a[i][j]=='#')
      {
        row[i]=true;
        col[j]=true;
      }
    }
  }

  //output
  for(int i=0;i<h;i++)
  {
    if(row[i]) {
                for(int j=0;j<w;j++)
                  {
                    if(col[j]) cout<<a[i][j];
                  }
                  cout<<endl;
                }

  }
}