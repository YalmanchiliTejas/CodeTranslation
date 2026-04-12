#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    char x[4];
    cin>>x;
    if(strcmp(x,"BBB")==0||strcmp(x,"AAA")==0)
        cout<<"No";
    else
        cout<<"Yes";
return 0;
}
