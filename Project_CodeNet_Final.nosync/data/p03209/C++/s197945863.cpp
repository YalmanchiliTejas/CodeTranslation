#include <iostream>
#include "bits/stdc++.h"
using namespace std;

typedef long long LL;

vector<LL> levels(55);
vector<LL> patties(55);

LL calc_layers(int N)
{
    levels[0] = 1;
    for (int i = 1;i < N + 1; i++)
    {
        levels[i] = 2*levels[i - 1] + 2 + 1;
    }
    return levels[N];
}

void calc_patties(int N)
{
    patties[0] = 1;
    for (int i = 1;i < N + 1; i++)
    {
        patties[i] = 2*patties[i - 1] + 1;
    }
}

int main() {
    int N;
    LL X;
    cin >> N >> X;
    LL number_layers = calc_layers(N);
    calc_patties(N);
        int L = N;
        LL p = 0;
        while (L > 1) {
            if (X < (number_layers + 1) / 2) // first half of the burguer
            {

                X--;
            } else if (X > (number_layers + 1) / 2) {
                p += patties[L - 1] + 1;
                X -= (number_layers + 1) / 2;
            } else {
                p += patties[L - 1] + 1;
                X = 0;
                break;
            }
            L--;
            number_layers = levels[L];
        }
        if (X > 1 and X < 5)
            p += X - 1;
        else if (X >= 5)
            p += 3;

        cout << p;
    return 0;
}