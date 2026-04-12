#include <cstdio>
#include <iostream>

int main ()
{
    using namespace std;
    int a, b;

    cin >> a >> b;
    printf("a %s b\n", (a < b)? "<" : (a > b)? ">" : "==" );
}