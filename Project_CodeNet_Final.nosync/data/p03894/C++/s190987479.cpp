#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
int main(void){
    int n, q;
    cin >> n >> q;
    
    int in[100010], num[100010];
    for (int i = 0; i < n; i++) num[i] = i;
    fill(in, in + n, 0);
    in[0] = 2;
    in[1] = 1;
    
    int aim = 0;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;  b--;
        //cout << num[a] << " " << num[b] << endl;
        
        if (in[a] == 2) {
            aim = b;
            in[a] = in[b];
            in[b] = 2;
        }
        else if (in[b] == 2) {
            aim = a;
            in[b] = in[a];
            in[a] = 2;
        }
        else {
            int ktmp = in[b];
            in[b] = in[a];
            in[a] = ktmp;
        }
        if (aim != 0) in[aim - 1] = 1;
        if (aim != n - 1) in[aim + 1] = 1;
        
        int tmp = num[b];
        num[b] = num[a];  num[a] = tmp;
        /*
        for (int i = 0; i < n; i++) {
            cout << in[i] << " ";
        }
        cout << endl;*/
    }
    
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] > 0) ans++;
        //cout << in[i] << " ";
    }
    /*cout << endl;
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    */
    cout << ans << endl;
    
}
