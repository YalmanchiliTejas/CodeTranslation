#include<stdio.h>
int a,b,c,n,m,answer;int s1,s2,s3,s4;
int main()
{  int max(int x,int y);
  int max1(int x,int y,int z);
   while(scanf("%d%d%d%d%d",&a,&b,&c,&n,&m)!=EOF)
   {
      if(n>m)
      {


        s1=(n-(n-m))*2*c+(n-m)*a;
        s2=n*2*c;
      }
        else
        {
            s1=(m-(m-n))*2*c+(m-n)*b;
            s2=m*2*c;
        }
        s3=a*n+b*m;
        answer=max1(s1,s2,s3);
        printf("%d\n",answer);


   }

}
int max(int x,int y)
{
    return x<y?x:y;
}
int max1(int x,int y,int z)
{
    int a;
    a=max(x,y);
    return a<z?a:z;
}