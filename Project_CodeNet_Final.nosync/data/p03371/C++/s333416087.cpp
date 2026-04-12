#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,y,x,i,j,k;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);

    vector <int> v;
    int sum;

    // only a b
    sum = a*x+b*y;
    v.push_back(sum);

    // only c
    int n= max(x,y);
    sum = n*2*c;
    v.push_back(sum);

    // b direct, a share
    sum = x*2*c;
    i = y - x;
    if(i>0)
    {
        sum = sum + (i*b);
       //printf("i %d ",i);
    }
    v.push_back(sum);

    // A direct, b share
    sum = y*2*c;
    i = x - y;
    if(i>0)
        {
            sum = sum + (i*a);
             //printf("j %d ",i);
        }
        v.push_back(sum);

    sort(v.begin(),v.end());

    printf("%d\n",v[0]);

   return 0;
}

