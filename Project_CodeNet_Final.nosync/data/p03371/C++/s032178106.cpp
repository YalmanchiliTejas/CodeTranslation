#include <bits/stdc++.h>

using namespace std;




int main()
{
int a,b,c,x,y;
int xn = 0;
int yn = 0;
int cena = 0;

    cin>>a>>b>>c>>x>>y;






    if((2*c) < (a + b))
    {

        while(xn < x && yn < y)
    {

        xn++;
        yn++;
        cena += (2*c);
    }

    }

    int naj = 0;
    int najm = 0;
    int g = 0;

    if(x > y)
    {

        naj = x;
        najm = y;
        g = a;
    }

    else
    {

        naj = y;
        najm = x;
        g = b;
    }


    if((2*c)*(naj - najm) < (naj-najm)*g )
    {

        cena += (2*c*(naj-najm));

    }
    else
    {

        while(xn < x || yn < y)
        {
            if(xn < x)
            {

                xn++;
                cena += a;

            }

            if(yn < y)
            {

                yn++;
                cena += b;

            }

        }
    }
    cout<<cena;






    return 0;
}
