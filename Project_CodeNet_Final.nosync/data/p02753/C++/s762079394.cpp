#include <iostream>

using namespace std;

int main()
{
    char str[3];
    scanf("%s", &str);
    if ((str[0]=='A' || str[1]=='A' || str[2]=='A') && (str[0]=='B' || str[1]=='B' || str[2]=='B'))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}