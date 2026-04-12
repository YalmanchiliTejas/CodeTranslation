// 23.07.2017


# include <iostream>


using namespace std;

int r, g, b;
bool ok;

int main ()
{
   cin >> r >> g >> b;

   ok = ( (g*10 + b) % 4 == 0 );

   if ( ok )
      cout << "YES";
   else
      cout << "NO";

   return 0;
}
