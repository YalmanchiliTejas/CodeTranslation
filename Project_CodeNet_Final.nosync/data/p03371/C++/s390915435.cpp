#include<iostream>

using namespace std;

int main()
{
    int a,b,c,x,y,price=0,price1=0;
    cin>>a>>b>>c>>x>>y;
    if((a>c)&(b>c)) //混合组价格最便宜
    {
        if(x<y)
        {
            price=2*x*c;
            y-=x;
            if((2*c)<b)
            {
                price=price+y*c*2;
            }
            else
            {
                price=price+y*b;
            }
        }
        else
        {
            price=2*y*c;
            x-=y;
            if((2*c)<a)
            {
                price=price+x*c*2;
            }
            else
            {
                price=price+x*a;
            }
        }
    }
    else if((c>a)&(c>b))  //混合组最贵
    {
        price=x*a+y*b;
    }
    else //仅南比混合贵
    {
        price1=y*b+a*x;//先管北，再管南
        int price2=0;
        if(y>x){
            price=2*c*x+(y-x)*b;//以混合为主
            price2=2*c*y;
        }else{
            price2=2*c*y+(x-y)*a;
            price=2*c*x;
        }

        if(price1<price)
            price=price1;
        if(price2<price)
            price=price2;
    }
    cout<<price<<endl;
    return 0;
}
