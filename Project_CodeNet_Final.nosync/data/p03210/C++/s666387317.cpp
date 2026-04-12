#include <iostream>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);

    int x;
    cin >> x;
    if (x == 7|| x == 5|| x == 3)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
