#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)

long num(int layer, long X);

long num_layer[55] = {1};
long num_pate[55]  = {1};

int main()
{
    for(int i = 1; i < 51; i++)
    {
        num_layer[i] = num_layer[i-1] * 2 + 3;
        num_pate[i]  = num_pate[i-1]  * 2 + 1;
    }

    //cout << "setting finish"<< endl;

    int N;
    long X;
    cin >> N >> X;

    //cout << "input N: " << N << " X: " << X << endl;
    long eat_pate = num(N, X);

    //cout << "finish calc." << endl;

    cout << eat_pate << endl;

}

long num(int layer, long X)
{
    long center = num_layer[layer-1] + 2;
    long eat_pate = 0;

    if (layer == 0)
    {
        return 1;
    }

    if (X < center)
    {
        long X_new = X - 1;
        if (X_new > 0)
        {
            eat_pate += num(layer-1, X_new);
        }
    }
    else if (X >= center)
    {
        // half-full
        eat_pate += 1 + num_pate[layer-1];
        
        long X_new = X - center; //cout << "new X: " << X_new << endl;
        if (X_new > 0)
        {
            eat_pate += num(layer-1, X_new);
        }
    }

    return eat_pate;
}