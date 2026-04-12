#include <iostream>

int main(){
    int H,W;scanf("%d %d\n",&H,&W);
    int a=0;
    char c;
    while (std::cin>>c) {
        if(c=='#')++a;
    }
    if(a==H+W-1)printf("Possible");
    else printf("Impossible");
}
