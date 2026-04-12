#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int,3> v;
    scanf("%d %d %d",&v[0],&v[1],&v[2]);
    if((v[2]+v[1]*10)%4==0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}