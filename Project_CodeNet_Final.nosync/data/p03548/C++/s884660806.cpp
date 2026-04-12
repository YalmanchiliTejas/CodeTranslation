#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <climits>

using namespace std;
 
int main()
{
    int X,Y,Z;
    cin >> X >> Y >> Z;
   
    int n=(int)(X-Z)/(Y+Z);
	cout<<n<<endl;

    return 0;
}