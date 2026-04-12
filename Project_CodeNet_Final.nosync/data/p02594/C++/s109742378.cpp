#include<bits/stdc++.h>
using namespace std;
void solveA()
{
  long long a,b,tem;
  cin>>a>>b;
  tem=(a+b);
  if(tem%2==0)
  {
    cout<<tem/2<<endl;
  }
  else
  {
    cout<<"IMPOSSIBLE"<<endl;
  }
}
void solveB()
{
  int n,i,j,count;
  cin>>n;
  int ar[n];
  for(i=0;i<n;i++)
  {
    cin>>ar[i];
  }
  j=1;
  count=0;
  for(i=0;i<n;i++)
  {
    if(ar[i]!=j)
    {
      count++;
    }
    if(count>2)
    {
      cout<<"NO"<<endl;
      return;
    }
    j++;
  }
  cout<<"YES"<<endl;
}
void solveC()
{
  int a,b,x,y;
  cin>>a>>b;
  x=max(a,b);
  y=min(a,b);
  if((x-y)>=2)
  {
    cout<<2*x-1<<endl;
  }
  else
  {
    cout<<x+y<<endl;
  }
}
void solveD()
{
  int n,i,j;
  cin>>n;
  int ar[n];
  for(i=0;i<n;i++)
  {
    cin>>ar[i];
  }
  int count=n;
  for(i=n-1;i>=0;i--)
  {
    for(j=i-1;j>=0;j--)
    {
      if(ar[i]<ar[j])
      {
        count--;
        break;
      }
    }
  }
  cout<<count<<endl;
}
void solveE()
{
  int h,w,x,y,H,W;
  cin>>H>>W;
  cin>>h>>w;
  x=h*W;
  y=(H-h)*w;
  cout<<(H*W)-(x+y)<<endl;
}
void solveF()
{
  int n,m,c,i,j;
  cin>>n>>m>>c;
  int b[m];
  int ar[n][m];
  for(i=0;i<m;i++)
  {
    cin>>b[i];
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      cin>>ar[i][j];
    }
  }
  int count=0;
  int sum;
  for(i=0;i<n;i++)
  {
    sum=0;
    for(j=0;j<m;j++)
    {
      sum=sum+ar[i][j]*b[j];
    }
    if((sum+c)>0)
    {
      count++;
    }
  }
  cout<<count<<endl;
}
void solveG()
{
  int a,b,c,tem;
  cin>>a>>b>>c;
  tem=b/a;
  if(tem>c)cout<<c<<endl;
  else cout<<tem<<endl;
}
void solveH()
{
  int a,b,c,tem,i;
  cin>>a>>b>>c;
  tem=min(a,b);
  vector<int>vec;
  for(i=1;i<=tem;i++)
  {
    if(a%i==0&&b%i==0)
    {
      vec.push_back(i);
    }
  }
  cout<<vec[vec.size()-c]<<endl;
}
void solveI()
{
  double t,x;
  cin>>t>>x;
  cout<<fixed<<setprecision(10)<<t/x<<endl;
}
void solveJ()
{
  int n,i;
  cin>>n;
  int ar[n];
  for(i=0;i<n;i++)
  {
    cin>>ar[i];
  }
  sort(ar,ar+n);
  int sum=0;
  for(i=0;i<n-1;i++)
  {
    sum=sum+ar[i];
  }
  if(ar[n-1]<sum)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
void solveK()
{
  int A,B,x,y;
  cin>>A>>B;
  x=max((A+B),(A-B));
  y=max(x,A*B);
  cout<<y<<endl;
}
void solveM()
{
  int i,j;
  char ar[3][3];
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      cin>>ar[i][j];
    }
  }
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(i==j)cout<<ar[i][j];
    }
  }
}
bool check(int n)
{
  int sum=0,t,tem=n;
  while(tem!=0)
  {
    t=tem%10;
    sum=sum*10+t;
    tem=tem/10;
  }
  if(sum==n)return 1;
  else return 0;
}
void solveN()
{
  int a,b,i;
  cin>>a>>b;
  int count=0;
  for(i=a;i<=b;i++)
  {
    if(check(i))count++;
  }
  cout<<count<<endl;
}
void solveO()
{
  int tem;
  cin>>tem;
  if(tem>=30)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
int main()
{
  // solveA();
  //solveB();
  // solveC();
  // solveD();
// solveE();
 //solveF();
// <solveG();
//solveH();
//solveI();
//solveJ();
//solveK();
//solveM();
//solveN();
solveO();
  return 0;
}