#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <limits>
using namespace std;

int main()
{
int n,i=0; cin>>n;
double x= 800.0 * n;
while(n>=15) {n-=15; i++;}
double y=200.0*i;
cout<<x-y;
}
