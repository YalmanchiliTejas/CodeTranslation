#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N;
    int view = 0,maior = 0;
    cin >> N;
    for (int i = 0 ; i < N ; i++)
    {
        int tam;
        cin >> tam;
        if(tam >= maior)
        {
            maior = tam;
            view++;
        }
    }
    cout << view << endl;
    return 0;
}