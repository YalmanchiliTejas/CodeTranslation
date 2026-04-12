#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define REP(i,n) for(int i = 0; i < n; i++)

int main(void)
{
    int N;
    cin >> N;
    int H[N];
    for(int i = 0; i < N; i++)
        cin >> H[i];
    
    int height = 0;
    int res = 0;
    for(int i = 0; i < N; i++)
    {
        if(H[i] >= height)
        {
            res++;
            height = H[i];
        }
    }
    cout << res <<endl;

    return 0; 
}
