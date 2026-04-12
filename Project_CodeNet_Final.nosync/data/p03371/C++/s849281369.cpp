#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    long long int a,b,c,x,y,ans=0,max,temp;
    cin>>a>>b>>c>>x>>y;
    max=x*a+y*b; //x个a元的，y个b元的，这个应该是最大的，再看后面的咯
    ans=max;
    temp=max;
    while(x>0&&y>0)
    {
        temp=temp-a-b+2*c;
        //cout<<temp<<endl;
        if(temp<max)
        {
            max=temp;
            ans=temp;
        }
        else
            break;
        x--;
        y--;
    }
    while(x>0)
    {
        temp=temp-a+2*c;
        //cout<<temp<<endl;
        if(temp<max)
            {
                max=temp;
                ans=temp;
            }
        else
            break;
        x--;
    }
    while(y>0)
    {
        temp=temp-b+2*c;
        //cout<<temp<<endl;
        if(temp<max)
            {
                max=temp;
                ans=temp;
            }
        else
            break;
        y--;
    }
    cout<<ans<<endl;
    return 0;
}
