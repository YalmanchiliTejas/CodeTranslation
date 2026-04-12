#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;

int main(void){
    int n;
    char p[100010];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    
    for (int i = 1; i < n; i++) {
        if (p[i - 1] == 'F') {
            if (p[i] =='F') p[i] = 'T';
        }
    }
    
    cout << char(p[n - 1]) << endl;
}

