# include<iostream>
using namespace std;

int main(void)
{
    int a, b, c, x, y;

    while(cin >> a >> b >> c >> x >> y && a!=0)
    {
        int sum = 0;
        if(c*2 < a+b)
        {
            if(x > y)
            {
                sum = y*2*c;
               // cout << "y*2=" << y*2<<endl;
                x -= y;
              //  cout << "x=" << x<<endl;
                if(c*2 < a)
                {
                    sum += (x*2*c);
                }
                else
                    sum += (x*a);
            }
            else
            {
                sum = x*2*c;
               // cout << "x*2=" << x*2<<endl;
                y -= x;
              //  cout << "y=" << y<<endl;
                if(c*2 < b)
                {
                    sum += (y*2*c);
                }
                else
                    sum += (y*b);
            }
            cout << sum << endl;
        }
        else
        {
            sum = x*a+b*y;
            cout << sum << endl;
        }
    }
    return 0;
}
