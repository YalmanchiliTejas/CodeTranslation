#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;



int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        int ans=(a-c)/(b+c);
        cout<<ans<<endl;
    }
    return 0;
}
