#include <iostream> 
using namespace std;
 int main ()
{
int N ;
cin >> N ;
int B=N/15 ;
int Z =N*800;
int X = Z-(B*200);
if ( N  <15)
cout << Z;
else if (N>15)
cout << X;

return 0;
} 