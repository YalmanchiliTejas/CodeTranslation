#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
using namespace std;

#define INF 1<<21
#define MOD 1000000007

int main(){
    int x,y,z;
    int ans=0;
    cin>>x>>y>>z;
    x-=2*z+y;
    ans=x/(y+z);
    cout<<ans+1<<endl;
    return 0;
}
