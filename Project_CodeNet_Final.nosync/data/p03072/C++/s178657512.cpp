#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int N; cin >> N;
    int top = 0;
    int total = 0;

    for(int i = 0; i < N; ++i)
    {
        int h;

        cin >> h;

        if(h >= top)
        {
            top = h;
            total++;
        }
    }

    cout << total << endl;


    return 0;
}