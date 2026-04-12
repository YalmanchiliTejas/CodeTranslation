#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int min = 1 << 30;
    
    for (int i = 0; i <= (x > y ? x : y); i++){
        int Apizza, Bpizza, ABPizza;
        Apizza = i;
        ABPizza = (((x > y ? x : y) - i) * 2 > 0 ? ((x > y ? x : y) - i) * 2 : 0);
        Bpizza = ((x > y ? y : x) - ((x > y ? x : y) - i) > 0 ? (x > y ? y : x) - ((x > y ? x : y) - i) : 0);

        int64_t cost = (x > y ? a : b) * Apizza + (x > y ? b : a) * Bpizza + c * ABPizza;
        if (min > cost){
            min = cost;
        }
    }

    cout << min << endl;
}