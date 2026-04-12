#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int N;
    
    cin >> N;
    
    printf("%d\n", N * 800 - (N / 15) * 200);
    
    return 0;
}
