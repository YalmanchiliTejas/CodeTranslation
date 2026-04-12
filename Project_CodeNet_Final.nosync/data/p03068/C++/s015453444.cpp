#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    string S;
    cin >> S;

    int K;
    cin >> K;

    char c = S.at(K - 1);

    for(int i= 0; i < N; i++)
    {
        if(S.at(i) != c)
        {
            S.at(i) = '*';
        }
    }

    cout << S << endl;
}