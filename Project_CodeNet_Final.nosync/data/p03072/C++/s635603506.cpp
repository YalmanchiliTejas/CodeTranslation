#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int x;
    cin >> x;

    int qtd = 0;

    int maior = 0;
    while (x--) {
        int y;
        cin >> y;
        if (y >= maior) {
            qtd++;
            maior = y;
        }
    }

    cout << qtd << endl;
    
    return 0;
}