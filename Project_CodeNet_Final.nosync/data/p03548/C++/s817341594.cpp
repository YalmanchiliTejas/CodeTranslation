#include <iostream>
#include <cstdlib>
#include<string>
#include<stdlib.h>
#include<math.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};


int main()
{
    int x,y,z;
    int ans;
    
    cin>>x>>y>>z;
    ans=x/(y+z);
    x-=ans*(y+z);
    if(x<z)ans--;
    cout<<ans<<endl;
    
    return 0;
}
