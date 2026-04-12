#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int x, y, z, i;
int main(int argc, const char * argv[]){
    cin>>x>>y>>z;
    i = 0;
    for(i = 0; (i * y) + (i + 1) * z <= x; i++){}
    if(i * y + (i + 1) * z > x)i--;
    cout<<i<<endl;
    return 0;
}