#include <stdio.h>

int main()
{
    char b,c,d;
    scanf("%c",&b);
    scanf("%c",&c);
    scanf("%c",&d);
    if((b=='A'||b=='B')&&(c=='A'||c=='B')&&(d=='A'||d=='B')){
        if(b==c&&c==d){
            printf("No");
        }
        else printf("Yes");
        }
    return 0;
}
