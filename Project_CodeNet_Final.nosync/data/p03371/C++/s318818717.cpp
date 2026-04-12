#include <iostream>

using namespace std;

int main()
{
    long long a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    long long sum=0;
    if ((a+b) <=(c*2))
    {
        sum=a*x+b*y;
    }
    else if ((a+b)>(c*2))
    {
        long long d=(x>=y)?y:x;
        sum=c*2*d;
        if (d==y)
        {
            x=x-d;
            if (a<=c*2)
                sum=sum+a*x;
            else
                sum=sum+x*c*2;
        }
        else
        {
            y=y-d;
            if (b<=c*2)
                sum=sum+b*y;
            else
                sum=sum+y*c*2;
        }
    }
    cout<<sum<<endl;
    return 0;
}



/*
  int N,X,cnt=0,sum=0;
  int a[105],b[105];
  cin>>N>>X;
  for (int i = 0; i < N; i++)
      cin>>a[i];
  int t;
  for (int j = 0,r=0; j<N; j++)
  {
      if (a[j]!=0)
      {
          b[r++]=a[j];
          for (int i = j+1; i<N ; i++)
          {
              if (a[i]==a[j])
                  a[i]=0;
          }
      }
      t=r;
  }
  for (int i=0;i<t;i++)
      cout<<b[i]<<endl;
  int mins=b[0];
  for (int r=0; r<t; r++)
      if (b[r]<mins)
          mins=b[r];
  for (int r=0; r<t; r++)
  {
      sum+=b[r];
      cnt++;
  }
  cnt=cnt+(X-sum)/mins;
  cout<<cnt<<endl;

  */
