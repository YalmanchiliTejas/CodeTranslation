#include<iostream>
 using namespace std;

int main ()
{
    int r,g,b;
    int d,e,f,h;
    cin >>r>>g>>b;
    d = r*100;
    e = g*10;
    f = b*1;
    h = d+e+f;
    if(h%4 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
