#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int H, W;
    char A;
    int count = 0;
    
    cin >> H >> W;
    
    for (int i = 0; i < H * W; i++)
    {
        cin >> A;
        if (A == '#')
        {
            count++;
        }
    }
    
    printf("%s\n",
        count == (H + W - 1) ? "Possible" : "Impossible");
    
    return 0;
}
