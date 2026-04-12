#include <iostream>
#include <string>

using namespace std;

int absy(int x){return x>0?x:-x;}

int main(void){
    int X;
    scanf("%d",&X);
    if(X==3||X==5||X==7)printf("YES");
    else printf("NO");
    return 0;
}
